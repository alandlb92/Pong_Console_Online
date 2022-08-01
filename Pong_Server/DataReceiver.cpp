#include "DataReceiver.h"

void DataReceiver::Distribute(ClientData clientData, int clientId)
{
	//TODO 
	//Here a temporary possess for tests
	if (Racketplayer1->GetClientId() == -1)
		Racketplayer1->Posses(clientId);
	else if (Racketplayer2->GetClientId() == -1 && Racketplayer1->GetClientId() != clientId)
		Racketplayer2->Posses(clientId);


	if (Racketplayer1->GetClientId() == clientId)
		Racketplayer1->UpdateRacketState(clientData._InputState);
	else if (Racketplayer2->GetClientId() == clientId)
		Racketplayer2->UpdateRacketState(clientData._InputState);
}