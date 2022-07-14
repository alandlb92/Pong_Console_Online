#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <sstream>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class EchoWebsocket
{
private:
	websocket::stream<beast::tcp_stream> ws;
	beast::flat_buffer buffer;
	bool canSendAndReceiveData = false;

public:

	EchoWebsocket(tcp::socket&& socket) : ws(std::move(socket)) {}
	~EchoWebsocket() {}

	void run();
	void echo();
	void sendMesage(std::string msg);
};

