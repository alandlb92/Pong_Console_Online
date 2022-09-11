#pragma once
#include <iostream>
#include <vector>

class Component
{
	friend class ActorBase;

private:
	void SetBaseActor(class ActorBase* baseActor);

protected:
	bool _isPhysicsComponent = false;
	class ActorBase* BaseActor;

public:
	virtual void Start();
	virtual void Update(double DeltaTime);
	virtual void FixedUpdate(double DeltaTime);

	bool IsPhysicsComponent() { return _isPhysicsComponent; };
};

