#pragma once
#include "ServerData.h"

class DataReceiver
{
public:
	std::function<void(Vector2)> SetBallPosition;
	std::function<void(Vector2)> SetRacketplayer1Position;
	std::function<void(Vector2)> SetRacketplayer2Position;
	void Distribute(ServerData serverData);
};

