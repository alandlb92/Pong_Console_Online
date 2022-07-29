#pragma once
#include "ActorBase.h"

class RacketActor : public ActorBase
{
private:
	typedef ActorBase super;

public:
	void SetPosition(Vector2 position);
	virtual void Start() override;
	virtual void Update(double deltaTime) override;
};

