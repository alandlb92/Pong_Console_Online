#pragma once
#include "ClientData.h"
#include "ServerData.h"
#include "InputState.h"
#include "Racket.h"

class DataReceiver
{
public:
	Racket* Racketplayer1;
	Racket* Racketplayer2;
	void Distribute(ClientData clientData, int clientId);
};

