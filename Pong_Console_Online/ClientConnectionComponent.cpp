#include "ClientConnectionComponent.h"


ClientConnectionComponent::ClientConnectionComponent(std::string serverURL)
{
    net::io_context ioc;
    tcp::resolver resolver{ ioc };
    websocket::stream<tcp::socket> ws{ ioc };


    tcp::endpoint endPoint = tcp::endpoint(net::ip::make_address("127.0.0.1"), 5050);
    auto const results = resolver.resolve(endPoint);
    auto ep = net::connect(ws.next_layer(), results);

    ws.set_option(websocket::stream_base::decorator(
    [](websocket::request_type& req)
    {
        req.set(http::field::user_agent,
            std::string(BOOST_BEAST_VERSION_STRING) +
            " websocket-client-coro");
    }));
    ws.handshake(serverURL, "/");

    ws.write(net::buffer(std::string("Hello Server From client test")));
    beast::flat_buffer buffer;
    ws.read(buffer);

    std::cout << beast::make_printable(buffer.data()) << std::endl;
}