#pragma once
class SerializeTests
{
public:
	void Run();
private:
	void ClientDataTest();
	void ServerDataTest();

	bool CompareClientData(class ClientData a, class ClientData b);
	bool CompareServerData(class ServerData a, class ServerData b);
};

