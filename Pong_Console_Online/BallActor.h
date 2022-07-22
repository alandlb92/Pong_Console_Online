#pragma once
#include "ActorBase.h"
#include "ServerData.h"
class BallActor : public ActorBase
{
private:
	typedef ActorBase super;

public:
	void SetPosition(Vector2 position);
	virtual void Start() override;
	virtual void Update(double DeltaTime) override;


};

