#pragma once
#include "ActorBase.h"
#include <iostream>
#include <functional>

class BallActor : public ActorBase
{
private:
	typedef ActorBase super;
	float velocity = 10;
	bool toRight = true;
	std::function<void(int)> OnScore;
	bool Stoped = true;


public:
	BallActor(std::function<void(Vector2)> updateOnlineBallPosition/*, std::function<void(int)> onScore*/) : UpdateOnlinePosition(updateOnlineBallPosition)/*, OnScore(onScore)*/ {}
	std::function<void(Vector2)> UpdateOnlinePosition;

	virtual void Start() override;
	virtual void Update(double DeltaTime) override;
	virtual void OnCollisionEnter(std::vector<ActorBase*> others) override;

};

