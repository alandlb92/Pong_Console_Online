#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem(bool& gameIsRunning, Scene& scene) : e_gameIsRunning(gameIsRunning), _currentScene(scene)
{
	_physicsThread = new std::thread(&PhysicsSystem::PhysiscsThread, this);
}

PhysicsSystem::~PhysicsSystem()
{
	_physicsThread->join();
}

void PhysicsSystem::PhysiscsThread()
{
	while (e_gameIsRunning)
	{
		Sleep(PhysicsDelayMS);
		if (e_gameIsRunning)
			Update();
	}
}

void PhysicsSystem::Update()
{
	CalculateCollisions();
}


void PhysicsSystem::CalculateCollisions()
{
	std::vector<std::pair<ActorBase*, BoxColliderComponent*>> ActorsColliders;
	GetActorWithColliders(ActorsColliders);

	std::vector<ActorBase*> Collisions;

	for (std::pair<ActorBase*, BoxColliderComponent*> ac : ActorsColliders)
	{
		UpdateCollisionAndCallEvents(ac, ActorsColliders);
	}
}

void PhysicsSystem::UpdateCollisionAndCallEvents(std::pair<ActorBase*, BoxColliderComponent*>& actor, std::vector<std::pair<ActorBase*, BoxColliderComponent*>>& actorList)
{

	std::vector<ActorBase*> Others;

	for (std::pair<ActorBase*, BoxColliderComponent*> a : actorList)
	{
		if (actor.first == a.first)
			continue;

		if (IsColliding(actor, a))
		{
			Others.push_back(a.first);
		}
	}

	if (Others.size() > 0)
	{
		if (actor.second->isInCollision)
			actor.first->OnCollisionStay(Others);
		else
			actor.first->OnCollisionEnter(Others);

		actor.second->isInCollision = true;
	}
	else
	{
		if (actor.second->isInCollision)
			actor.first->OnCollisionExit(Others);

		actor.second->isInCollision = false;
	}

}


bool  PhysicsSystem::IsColliding(std::pair<ActorBase*, BoxColliderComponent*>& A, std::pair<ActorBase*, BoxColliderComponent*>& B)
{
	Vector2 minA;
	Vector2 minB;
	Vector2 maxA;
	Vector2 maxB;

	A.second->GetMin(minA);
	B.second->GetMin(minB);
	A.second->GetMax(maxA);
	B.second->GetMax(maxB);

	bool resultX = (minB.x >= minA.x && minB.x <= maxA.x) || (maxB.x >= minA.x && maxB.x <= maxA.x);
	bool resultY = (minB.y >= minA.y && minB.y <= maxA.y) || (maxB.y >= minA.y && maxB.y <= maxA.y);

	return resultX && resultY;
}

void  PhysicsSystem::GetActorWithColliders(std::vector<std::pair<ActorBase*, BoxColliderComponent*>>& actorColliders)
{
	for (int i = 0; i < _currentScene.GetActorCount(); i++)
	{
		ActorBase* Actor = _currentScene.GetActors()[i];
		std::vector<BoxColliderComponent*> Colliders = Actor->GetComponents<BoxColliderComponent>();

		if (Colliders.size() > 0)
			actorColliders.push_back({ Actor, Colliders[0] });
	}
}