#include "BallActor.h"
#include "BoxColliderComponent.h"

void BallActor::Start()
{
	super::Start();
	transform->position = Vector2(0, 25);
	velocity = 10;

	AddComponent(new BoxColliderComponent(2, 2));
}

void BallActor::Update(double DeltaTime)
{
	super::Update(DeltaTime);
	if (Stoped) {
		UpdateOnlinePosition(transform->position);
		return;
	}
	//if (transform->position.x > 100.0f && toRight)
	//	OnScore(1);
	//else if (transform->position.x < 0.0f && !toRight)
	//	OnScore(2);


	if (toRight)
		transform->position.x += (velocity * (float)DeltaTime);
	else
		transform->position.x -= (velocity * (float)DeltaTime);

	if (UpdateOnlinePosition)
		UpdateOnlinePosition(transform->position);
}

void BallActor::OnCollisionEnter(std::vector<ActorBase*> others)
{
	if (Stoped)
	{
		Stoped = false;
		toRight = true;
	}
	else
		toRight = !toRight;
}