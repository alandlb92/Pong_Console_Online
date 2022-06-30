#pragma once
#include <list>
#include "Component.h"
#include "Transform.h"

class ActorBase
{
private:
	std::list<Component*> components;

public:
	ActorBase();
	Transform* transform;
	void AddComponent(Component* component);
};

