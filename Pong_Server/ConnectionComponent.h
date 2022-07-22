#pragma once
#include "Component.h"
#include "WebListener.h"
#include "ServerData.h"

class ConnectionComponent : public Component
{
public:
	ConnectionComponent(bool& gameIsRunning) : e_gameIsRunning(gameIsRunning), _serverData(ServerData{}), _webListener(nullptr) {};
	~ConnectionComponent();

	typedef Component super;	
	WebListener* _webListener;

	virtual void Start();
	virtual void Update(double DeltaTime);

	void UpdateBallPosition(Vector2 position);

private:
	ServerData _serverData;
	int const port = 5050;
	net::io_context ioc;
	bool& e_gameIsRunning;
	std::thread* _webThread = nullptr;
	void WebThread();

};

