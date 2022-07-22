#include "ConnectionComponent.h"


void ConnectionComponent::Start()
{
	super::Start();
	_webListener = new WebListener(ioc, port);
	_webListener->asyncAccept();
	_webThread = new std::thread(&ConnectionComponent::WebThread, this);
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