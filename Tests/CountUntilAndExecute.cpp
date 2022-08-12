#include "CountUntilAndExecute.h"

void CountUntilAndExecute::Update(double DeltaTime)
{
	super::Update(DeltaTime);
	counter += DeltaTime;
	if (counter >= countUntil)
	{
		OnExecute();
	}
}