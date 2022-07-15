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

class ClientWebsocketConnection
{
private:
	websocket::stream<beast::tcp_stream> ws;
	beast::flat_buffer buffer;
	bool canSendAndReceiveData = false;
	std::function<void(ClientWebsocketConnection*)> OnDisconectClient;

public:

	ClientWebsocketConnection(tcp::socket&& socket, std::function<void(ClientWebsocketConnection*)> _onDisconectClient) : ws(std::move(socket)), OnDisconectClient(_onDisconectClient) {}
	~ClientWebsocketConnection() {}

	void run();
	void echo();
	void sendMesage(std::string msg);
};

