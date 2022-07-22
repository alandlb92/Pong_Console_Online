#include "BallActor.h"

void BallActor::Start()
{
	super::Start();
	transform->position = Vector2(25);
	velocity = 10;
}

void BallActor::Update(double DeltaTime)
{
	super::Update(DeltaTime);

	if (transform->position.x >= 50.0f && toRight) 
		toRight = false;	
	else if (transform->position.x <= 0.0f && !toRight)
		toRight = true;


	if (toRight)
		transform->position.x += (velocity * DeltaTime);
	else
		transform->position.x -= (velocity * DeltaTime);

	if (updateOnlinePosition)
		updateOnlinePosition(transform->position);
}
