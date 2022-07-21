#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include "ClientData.h"
#include <boost/archive/text_iarchive.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;
using namespace boost::archive;

class ClientWebsocketConnection
{
private:
	websocket::stream<beast::tcp_stream> ws;
	beast::flat_buffer buffer;
	bool canSendAndReceiveData = false;
	std::function<void(ClientWebsocketConnection*)> OnDisconectClient;
	ClientData _data;

public:

	ClientWebsocketConnection(tcp::socket&& socket, std::function<void(ClientWebsocketConnection*)> _onDisconectClient) : ws(std::move(socket)), OnDisconectClient(_onDisconectClient) {}
	~ClientWebsocketConnection() {}

	void run();
	void echo();
	void sendMesage(std::string msg);
};

