#include "ActorBase.h"

ActorBase::ActorBase()
{
	transform = new Transform();
	_componentsCount = 0;
}

void ActorBase::AddComponent(Component* component)
{
	Component** copy = (Component**)realloc(_components, sizeof(Component) * (_componentsCount + 1));
	if (copy == NULL)
		return;

	_components = copy;

	_components[_componentsCount] = component;
	_componentsCount++;
}


void ActorBase::Start()
{
	//std::cout << "Component Start" << std::endl;
	for (int i = 0; i < _componentsCount; i++)
	{
		_components[i]->Start();		
	}
}

void ActorBase::Update(double DeltaTime)
{
	//std::cout << "Component Update" << std::endl;
	for (int i = 0; i < _componentsCount; i++)
	{
		_components[i]->Update(DeltaTime);
	}
}