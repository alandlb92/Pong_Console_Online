#pragma once
#include <future>
#include "Scene.h"
#include "BoxColliderComponent.h"

class PhysicsSystem
{
public:
	PhysicsSystem(bool& gameIsRunning, Scene& scene);
	~PhysicsSystem();
private:
	int PhysicsDelayMS = 200;
	Scene& _currentScene;
	bool& e_gameIsRunning;
	std::thread* _physicsThread = nullptr;
	void PhysiscsThread();
	void Update();
	void CalculateCollisions();
	void UpdateCollisionAndCallEvents(std::pair<ActorBase*, BoxColliderComponent*>& actor, std::vector<std::pair<ActorBase*, BoxColliderComponent*>>& actorList);
	bool IsColliding(std::pair<ActorBase*, BoxColliderComponent*>& A, std::pair<ActorBase*, BoxColliderComponent*>& B);

	void GetActorWithColliders(std::vector<std::pair<ActorBase*, BoxColliderComponent*>>& actorColliders);
};

