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


    _readerThread = new std::thread(&ClientConnectionComponent::ReaderThread, this);
}

void ClientConnectionComponent::Start()
{
    super::Start();
    WriteData("Hello from Start");
}

void ClientConnectionComponent::Update(double deltaTime)
{
    super::Update(deltaTime);
    std::cout << dataTest;
}

void ClientConnectionComponent::WriteData(std::string msg)
{
    ws.write(net::buffer(std::string(msg)));
}

void ClientConnectionComponent::ReaderThread()
{
    beast::flat_buffer buffer;
    ws.read(buffer);
    std::stringstream ss;
    ss << beast::make_printable(buffer.data()) << std::endl;
    dataTest = ss.str();
}