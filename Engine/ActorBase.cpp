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

	component->SetBaseActor(this);

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


void ActorBase::AddTag(std::string newTag)
{
	_tags.push_back(newTag);
}

void ActorBase::RemoveTag(std::string tagToDelete)
{
	std::vector<std::string>::iterator it = std::find(_tags.begin(), _tags.end(), tagToDelete);
	_tags.erase(it);
}

bool ActorBase::ContainsTag(std::string tagName)
{
	for (std::string v : _tags)
	{
		if (v == tagName)
			return true;
	}

	return false;
}

void ActorBase::OnCollisionEnter(std::vector<ActorBase*> others)
{

}

void ActorBase::OnCollisionStay(std::vector<ActorBase*> others)
{

}

void ActorBase::OnCollisionExit(std::vector<ActorBase*> others)
{

}