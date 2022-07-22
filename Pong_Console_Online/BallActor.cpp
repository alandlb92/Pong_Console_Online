#include "BallActor.h"
void BallActor::Start()
{
	super::Start();
}

void BallActor::Update(double DeltaTime)
{
	super::Update(DeltaTime);		
}

void BallActor::SetPosition(Vector2 position)
{
	transform->position = position;
}