#include "RacketActor.h"

void RacketActor::Start() 
{
	super::Start();
}

void RacketActor::Update(double deltaTime)
{
	super::Update(deltaTime);
}


void RacketActor::SetPosition(Vector2 position)
{
	transform->position = position;
}