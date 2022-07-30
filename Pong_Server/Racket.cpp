#include "Racket.h"

void Racket::Start()
{
};

void Racket::Update(double DeltaTime)
{
	if (State == InputState::Up_Arrow)
	{
		transform->position.y -= (velocity * DeltaTime);
	}
	else if (State == InputState::Down_Arrow)
	{
		transform->position.y += (velocity * DeltaTime);
	}

	ClampPosition();
	if (OnUpdateRacketPosition)
		OnUpdateRacketPosition(transform->position);
};

void Racket::UpdateRacketState(InputState state)
{
	State = state;
}

void Racket::ClampPosition()
{
	if (transform->position.y <= 0)
		transform->position.y = 0;
}

int Racket::GetClientId()
{
	return clientId;
}

void  Racket::Posses(int _clientId)
{
	State = InputState::Idle;
	clientId = _clientId;
}