#pragma once
#include "ActorBase.h"
#include "InputState.h"

class Racket : public ActorBase
{
private:
	InputState State = InputState::Idle;
	void ClampPosition();
	std::function<void(Vector2)> OnUpdateRacketPosition;
	int clientId = -1;
	float velocity = 10;

public:
	Racket(std::function<void(Vector2)> onUpdateRacketPosition) : OnUpdateRacketPosition(onUpdateRacketPosition) {};

	void UpdateRacketState(InputState state);
	void Posses(int clientId);

	int GetClientId();
	virtual void Start() override;
	virtual void Update(double DeltaTime) override;
};

