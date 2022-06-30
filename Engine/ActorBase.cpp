#include "ActorBase.h"

ActorBase::ActorBase()
{
	transform = new Transform();
}

void ActorBase::AddComponent(Component* component)
{
	components.push_back(component);
}