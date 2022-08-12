#pragma once
#include "Engine.h"
#include "TestColliderActor.h"

class ColliderTests
{
public:
	ColliderTests();
	void Run();
	bool Result = false;	

private:
	Engine* _engine;
	std::map<int, int> countCollisionEnter;
	std::map<int, int> countCollisionStay;
	std::map<int, int > countCollisionExit;

	TestColliderActor* GetActorById(int id);
	void OnTimeOver();
	void PrintResults();
	void OnEnterCollider(int id, TestColliderActor::CollisionState state);
};

