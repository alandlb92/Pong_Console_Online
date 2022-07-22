#pragma once
#include "ActorBase.h"
#include <iostream>
#include <functional>

class BallActor : public ActorBase
{
private:
	typedef ActorBase super;
	float velocity;
	bool toRight = true;
public:
	BallActor(std::function<void(Vector2)> updateOnlineBallPosition) : updateOnlinePosition(updateOnlineBallPosition) {}
	std::function<void(Vector2)> updateOnlinePosition;

	virtual void Start() override;
	virtual void Update(double DeltaTime) override;
};

