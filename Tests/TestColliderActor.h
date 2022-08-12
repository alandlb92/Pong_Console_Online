#pragma once
#include "ActorBase.h"


class TestColliderActor : public ActorBase
{
public:
	enum class CollisionState
	{
		ENTER,
		STAY,
		EXIT
	};

private:
	int _id;
	typedef ActorBase super;
	std::function<void(int, CollisionState)> OnCollision;

public:
	TestColliderActor(int colliderWidht, int colliderHeight);
	void SetUp(std::function<void(int, CollisionState)> onCollision, int id);
	virtual void Start() override;
	virtual void OnCollisionEnter(std::vector<ActorBase*> others) override;
	virtual void OnCollisionStay(std::vector<ActorBase*> others) override;
	virtual void OnCollisionExit(std::vector<ActorBase*> others) override;
	const int GetId() { return _id; }
};

