#include "ConnectionComponent.h"


void ConnectionComponent::Start()
{
	super::Start();
	_webListener = new WebListener(ioc, port, bind(&ConnectionComponent::OnReceiveDataFromOneClient, this, std::placeholders::_1));
	_webListener->asyncAccept();
	_webThread = new std::thread(&ConnectionComponent::WebThread, this);
}

void ConnectionComponent::OnReceiveDataFromOneClient(ClientData clientData)
{
	OnReceiveData(clientData, _serverData);
}

void  ConnectionComponent::Update(double DeltaTime)
{
	super::Update(DeltaTime);
	_webListener->sendDataToAllClients(_serverData);
}

ConnectionComponent::~ConnectionComponent()
{
	if (_webThread != nullptr)
		_webThread->join();
}

void ConnectionComponent::WebThread()
{
	ioc.run();
}

void ConnectionComponent::UpdateBallPosition(Vector2 position)
{
	_serverData.BallPosition = position;
}


void ConnectionComponent::UpdateRacketPlayer1Position(Vector2 position)
{
	_serverData.RacketPlayer1Position = position;
}

void ConnectionComponent::UpdateRacketPlayer2Position(Vector2 position)
{
	_serverData.RacketPlayer2Position = position;
}