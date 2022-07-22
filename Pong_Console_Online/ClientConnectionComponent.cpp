#include "ClientConnectionComponent.h"


ClientConnectionComponent::ClientConnectionComponent(std::string serverIp, int port)
{
	std::stringstream serverURL;
	serverURL << "ws://" << serverIp << ":" << port;

	tcp::endpoint endPoint = tcp::endpoint(net::ip::make_address(serverIp), port);
	auto const results = resolver.resolve(endPoint);
	auto ep = net::connect(ws.next_layer(), results);

	ws.set_option(websocket::stream_base::decorator(
		[](websocket::request_type& req)
		{
			req.set(http::field::user_agent,
				std::string(BOOST_BEAST_VERSION_STRING) +
				" websocket-client-coro");
		}));
	ws.handshake(serverURL.str(), "/");
	ws.binary(true);

	_readerThread = new std::thread(&ClientConnectionComponent::ReaderThread, this);
}

void ClientConnectionComponent::Start()
{
	super::Start();
}

void ClientConnectionComponent::Update(double deltaTime)
{
	super::Update(deltaTime);
}

void ClientConnectionComponent::WriteData()
{
	std::stringstream ss;
	text_oarchive oa{ ss };
	oa << _clientData;
	ws.write(net::buffer(ss.str()));
}

void ClientConnectionComponent::ReaderThread()
{
	beast::flat_buffer buffer;
	ws.read(buffer);
	auto out = beast::buffers_to_string(buffer.cdata());
	std::stringstream ss;
	ss << out;
	text_iarchive ia{ ss };
	ia >> _data;
	if (OnReceiveData)
		OnReceiveData(_data);
}


void ClientConnectionComponent::SetUpClientData(std::string name)
{
	_clientData.Name = name;
	WriteData();
}