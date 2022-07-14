#pragma once
#include "ActorBase.h"

class Player : public ActorBase
{
public:
	typedef Player super;
	void Start() override;
	void Update(double DeltaTime) override;
};

