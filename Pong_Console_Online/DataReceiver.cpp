#include "DataReceiver.h"

void DataReceiver::Distribute(ServerData serverData)
{
	if (SetBallPosition) 
		SetBallPosition(serverData.BallPosition);
	if (SetRacketplayer1Position)
		SetRacketplayer1Position(serverData.RacketPlayer1Position);
	if (SetRacketplayer2Position)
		SetRacketplayer2Position(serverData.RacketPlayer2Position);
}