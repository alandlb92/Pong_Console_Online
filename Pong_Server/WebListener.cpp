#include "WebListener.h"

void WebListener::asyncAccept()
{
	acceptor.async_accept(ioc, [this](boost::system::error_code sysError, tcp::socket socket) {
		ClientWebsocketConnection* client = new ClientWebsocketConnection(std::move(socket), std::bind(&WebListener::removeClient, this, std::placeholders::_1));
		addClient(client);
		client->run();
		asyncAccept();
		});
}



void WebListener::addClient(ClientWebsocketConnection* client)
{
	std::cout << "New Client conected" << std::endl;

	ClientWebsocketConnection** copy = (ClientWebsocketConnection**)realloc(_clients, (_clientsCount + 1) * sizeof(ClientWebsocketConnection*));
	if (copy == NULL)
		return;

	_clients = copy;
	_clients[_clientsCount] = client;
	_clientsCount++;
	std::cout << "ClientCount: " << _clientsCount << std::endl;
}


void WebListener::removeClient(ClientWebsocketConnection* client)
{
	std::cout << "Client Disconected" << std::endl;

	int indexToDelete = -1;
	for (int i = 0; i < _clientsCount; i++)
	{
		if (_clients[i] == client) {
			indexToDelete = i;
			break;
		}
	}

	if (indexToDelete != _clientsCount - 1) {
		_clients[indexToDelete] = _clients[_clientsCount - 1];
		_clients[_clientsCount - 1] = nullptr;
	}

	_clientsCount--;
	if (_clientsCount == 0)
	{
		free(_clients);
		_clients = NULL;
	}
	else 
	{
		ClientWebsocketConnection** copy = (ClientWebsocketConnection**)realloc(_clients, (_clientsCount) * sizeof(ClientWebsocketConnection*));
		if (copy == NULL) {
			std::cout << "Error on Realloc" << _clientsCount << std::endl;
			return;
		}
		_clients = copy;
	}

	std::cout << "ClientCount: " << _clientsCount << std::endl;
}

void WebListener::sendDataToAllClients(ServerData serverData)
{
	for (int i = 0; i < _clientsCount; i++)
	{
		if (_clients[i] != nullptr)
			_clients[i]->sendMesage(serverData);
	}
}