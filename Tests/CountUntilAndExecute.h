#pragma once
#include "Component.h"
#include <functional>

class CountUntilAndExecute : public Component
{
private:
	typedef Component super;
	std::function<void()> OnExecute;
	double counter;
	double countUntil;

public:
	CountUntilAndExecute(std::function<void()> onExecute, double until) : OnExecute(onExecute), counter(0), countUntil(until) {};
	void Update(double DeltaTime) override;
};

