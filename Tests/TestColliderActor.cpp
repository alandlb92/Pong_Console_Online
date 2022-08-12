#include "TestColliderActor.h"
#include "BoxColliderComponent.h"

TestColliderActor::TestColliderActor(int colliderWidht, int colliderHeight)
{
	super::ActorBase();
	BoxColliderComponent* collider = new BoxColliderComponent(colliderWidht, colliderHeight);

	_id = -1;
	AddComponent(collider);
}

void TestColliderActor::SetUp(std::function<void(int, CollisionState)> onCollision, int id)
{
	_id = id;
	OnCollision = onCollision;
}

void TestColliderActor::Start()
{
}

void TestColliderActor::OnCollisionEnter(std::vector<ActorBase*> others)
{
	OnCollision(_id, CollisionState::ENTER);
}

void TestColliderActor::OnCollisionStay(std::vector<ActorBase*> others)
{
	OnCollision(_id, CollisionState::STAY);
}

void TestColliderActor::OnCollisionExit(std::vector<ActorBase*> others)
{
	OnCollision(_id, CollisionState::EXIT);
}