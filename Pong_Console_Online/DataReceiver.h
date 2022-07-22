#pragma once
#include "ServerData.h"

class DataReceiver
{
public:
	std::function<void(Vector2)> SetBallPosition;
	void Distribute(ServerData serverData);
};

