#pragma once
#include "Component.h"
#include <iostream>
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class ClientConnectionComponent : public Component
{
private:
	net::io_context ioc;
	tcp::resolver resolver;
	websocket::stream<tcp::socket> ws;

public:
	ClientConnectionComponent(std::string serverURL);

};

