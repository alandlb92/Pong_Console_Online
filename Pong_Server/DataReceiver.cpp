#include "DataReceiver.h"

void DataReceiver::Distribute(ClientData clientData, ServerData& serverDataReference)
{
	//TODO 
	//Here a temporary possess for tests
	if (Racketplayer1->GetClientId() == -1)
		Racketplayer1->Posses(clientData.Id);
	else if (Racketplayer2->GetClientId() == -1 && Racketplayer1->GetClientId() != clientData.Id)
		Racketplayer2->Posses(clientData.Id);


	if (Racketplayer1->GetClientId() == clientData.Id)
		Racketplayer1->UpdateRacketState(clientData._InputState);
	else if (Racketplayer2->GetClientId() == clientData.Id)
		Racketplayer2->UpdateRacketState(clientData._InputState);
}