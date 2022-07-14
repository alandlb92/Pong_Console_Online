#pragma once
#include "EchoWebsocket.h"

class WebListener
{
private:
	net::io_context& ioc;
	tcp::acceptor acceptor;
	EchoWebsocket** _clients;
	int _clientsCount = 0;

	void addClient(EchoWebsocket*);

public:
	WebListener(net::io_context& ioc,
		unsigned short int port) :ioc(ioc),
		acceptor(ioc, { net::ip::make_address("127.0.0.1"), port }) {}

	void asyncAccept();
	void sendMessageToAllClients(std::string msg);
};

