#pragma once
#include "ClientWebsocketConnection.h"
#include "ServerData.h"

class WebListener
{
private:
	net::io_context& ioc;
	tcp::acceptor acceptor;
	ClientWebsocketConnection** _clients;
	int _clientsCount = 0;

	void addClient(ClientWebsocketConnection*);
	void removeClient(ClientWebsocketConnection*);

public:
	WebListener(net::io_context& ioc,
		unsigned short int port) :ioc(ioc),
		acceptor(ioc, { net::ip::make_address("127.0.0.1"), port }),
		_clients(nullptr) {}

	void asyncAccept();
	void sendDataToAllClients(ServerData serverData);
};

