#pragma once
#include "Component.h"
#include "WebListener.h"

class ConnectionComponent : public Component
{
public:
	ConnectionComponent(bool& gameIsRunning) : e_gameIsRunning(gameIsRunning) {};
	~ConnectionComponent();

	typedef Component super;	
	WebListener* _webListener;

	virtual void Start();
	virtual void Update(double DeltaTime);


private:
	int const port = 5050;
	net::io_context ioc;
	bool& e_gameIsRunning;
	std::thread* _webThread = nullptr;
	void WebThread();

};

