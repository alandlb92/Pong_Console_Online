#include "WebListener.h"

void WebListener::asyncAccept()
{
	acceptor.async_accept(ioc, [this](boost::system::error_code sysError, tcp::socket socket) {
		EchoWebsocket* client = new EchoWebsocket(std::move(socket));
		addClient(client);
		client->run();
		std::cout << "Connection accepted" << std::endl;
		asyncAccept();
	});
}



void WebListener::addClient(EchoWebsocket* client)
{
	EchoWebsocket** copy = (EchoWebsocket**)realloc(_clients, (_clientsCount + 1) * sizeof(EchoWebsocket*));
	if (copy == NULL)
		return;

	_clients = copy;
	_clients[_clientsCount] = client;
	_clientsCount++;

}

void WebListener::sendMessageToAllClients(std::string msg)
{
	for (int i = 0;i < _clientsCount;i++)
	{
		_clients[i]->sendMesage(msg);
	}
}