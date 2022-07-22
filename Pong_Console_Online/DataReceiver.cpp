#include "DataReceiver.h"

void DataReceiver::Distribute(ServerData serverData)
{
	if (SetBallPosition)
		SetBallPosition(serverData.BallPosition);
}