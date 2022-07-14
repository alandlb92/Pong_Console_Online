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
	std::stringstream ss;
	ss << "Hello Client " << DeltaTime;
	_webListener->sendMessageToAllClients(ss.str());
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
