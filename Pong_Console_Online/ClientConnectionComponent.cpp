#include "ClientConnectionComponent.h"


ClientConnectionComponent::ClientConnectionComponent(std::string serverIp, int port)
{
    _clientData = nullptr;

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
    WriteData();
}

void ClientConnectionComponent::Update(double deltaTime)
{
    super::Update(deltaTime);
    std::cout << dataTest;
}

void ClientConnectionComponent::WriteData()
{
    std::stringstream ss;
    text_oarchive oa{ ss };
    oa << *_clientData;
    ws.write(net::buffer(ss.str()));
}

void ClientConnectionComponent::ReaderThread()
{
    beast::flat_buffer buffer;
    ws.read(buffer);
    std::stringstream ss;
    ss << beast::make_printable(buffer.data()) << std::endl;
    dataTest = ss.str();
}


void ClientConnectionComponent::SetUpClientData(std::string name)
{
    _clientData = new ClientData();
    _clientData->Name = name;
    WriteData();
}