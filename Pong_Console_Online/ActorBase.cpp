#include "ActorBase.h"

void ActorBase::AddComponent(Component* component)
{
	components.push_back(component);
}