#include "ColliderTests.h"
#include "ActorBase.h"
#include "CountUntilAndExecute.h"

/// <summary>
///  00 00
///  0x0x0
///   000  
///  0x0x0
///  00 00
/// 
/// 
/// 
/// </summary>



ColliderTests::ColliderTests()
{
	std::cout << "Start Collider Tests" << std::endl;

	_engine = nullptr;
	countCollisionEnter =
	{
		{ 1,0 },
		{ 2,0 },
		{ 3,0 },
		{ 4,0 },
		{ 5,0 }
	};
	countCollisionStay =
	{
		{ 1,0 },
		{ 2,0 },
		{ 3,0 },
		{ 4,0 },
		{ 5,0 }
	};
	countCollisionExit =
	{
		{ 1,0 },
		{ 2,0 },
		{ 3,0 },
		{ 4,0 },
		{ 5,0 }
	};
}

void ColliderTests::PrintResults()
{
	std::cout << "Collision test results" << std::endl;

	for (auto pair : countCollisionEnter)
	{
		std::cout << "Collision enter id: " << pair.first << " must be 1 " << " RESULT: " << pair.second << std::endl;
	}

	for (auto pair : countCollisionStay)
	{
		std::cout << "Collision stay id: " << pair.first << " must be greater than 5 " << " RESULT: " << pair.second << std::endl;
	}

	for (auto pair : countCollisionExit)
	{
		std::cout << "Collision exit id: " << pair.first << " must be 1 " << " RESULT: " << pair.second << std::endl;
	}
}

void ColliderTests::OnTimeOver()
{
	std::cout << "Collision Test Fail, Time Out" << std::endl;
	_engine->gameIsRunning = false;
	Result = false;
	PrintResults();
}

TestColliderActor* ColliderTests::GetActorById(int id)
{
	for (int i = 0; i < Game::GetInstance()->GetCurrentScene()->GetActorCount(); i++)
	{
		TestColliderActor* actor = static_cast<TestColliderActor*>(Game::GetInstance()->GetCurrentScene()->GetActors()[i]);
		if (actor && actor->GetId() == id)
			return actor;
	}

	return nullptr;
}

void ColliderTests::Run()
{
	_engine = new Engine(Vector2(150, 75), 50);
	CountUntilAndExecute* countUntil = new CountUntilAndExecute(std::bind(&ColliderTests::OnTimeOver, this), 5.0);

	TestColliderActor* actor1 = new TestColliderActor(3, 3);
	TestColliderActor* actor2 = new TestColliderActor(2, 2);
	TestColliderActor* actor3 = new TestColliderActor(2, 2);
	TestColliderActor* actor4 = new TestColliderActor(2, 2);
	TestColliderActor* actor5 = new TestColliderActor(2, 2);

	actor1->SetUp(std::bind(&ColliderTests::OnEnterCollider, this, std::placeholders::_1, std::placeholders::_2), 1);
	actor2->SetUp(std::bind(&ColliderTests::OnEnterCollider, this, std::placeholders::_1, std::placeholders::_2), 2);
	actor3->SetUp(std::bind(&ColliderTests::OnEnterCollider, this, std::placeholders::_1, std::placeholders::_2), 3);
	actor4->SetUp(std::bind(&ColliderTests::OnEnterCollider, this, std::placeholders::_1, std::placeholders::_2), 4);
	actor5->SetUp(std::bind(&ColliderTests::OnEnterCollider, this, std::placeholders::_1, std::placeholders::_2), 5);

	actor1->transform->position = Vector2(2);
	actor2->transform->position = Vector2(1);
	actor3->transform->position = Vector2(1, 4);
	actor4->transform->position = Vector2(4, 1);
	actor5->transform->position = Vector2(4);

	Scene scene = Scene("MainTest");

	scene.AddComponent(countUntil);

	scene.AddActor(actor1);
	scene.AddActor(actor2);
	scene.AddActor(actor3);
	scene.AddActor(actor4);
	scene.AddActor(actor5);

	_engine->Start(scene, true);

	assert(Result);
}


void ColliderTests::OnEnterCollider(int id, TestColliderActor::CollisionState state)
{
	switch (state)
	{
	case TestColliderActor::CollisionState::ENTER:
		countCollisionEnter[id]++;
		if (countCollisionEnter[1] == 1 && countCollisionEnter[2] == 1 && countCollisionEnter[3] == 1 && countCollisionEnter[4] == 1 && countCollisionEnter[5] == 1)
		{
			std::cout << "Enter collision enter pass" << std::endl;
		}
		break;
	case TestColliderActor::CollisionState::STAY:
		countCollisionStay[id]++;
		if (countCollisionStay[1] >= 5 && countCollisionStay[2] >= 5 && countCollisionStay[3] >= 5 && countCollisionStay[4] >= 5 && countCollisionStay[5] >= 5)
		{
			std::cout << "Enter collision stay pass" << std::endl;
			GetActorById(1)->transform->position = Vector2(0);
			GetActorById(2)->transform->position = Vector2(-10);
			GetActorById(3)->transform->position = Vector2(2, -10);
			GetActorById(4)->transform->position = Vector2(-10, 2);
			GetActorById(5)->transform->position = Vector2(10);
		}
		break;
	case TestColliderActor::CollisionState::EXIT:
		countCollisionExit[id]++;
		if (countCollisionExit[1] == 1 && countCollisionExit[2] == 1 && countCollisionExit[3] == 1 && countCollisionExit[4] == 1 && countCollisionExit[5] == 1)
		{
			std::cout << "Enter collision exit pass" << std::endl;
			_engine->gameIsRunning = false;
			Result = true;
			PrintResults();
		}
		break;
	default:
		break;
	}
}