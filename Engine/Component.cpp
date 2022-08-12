#include "Component.h"
#include <algorithm>
#include "ActorBase.h"

void Component::Start()
{
}

void Component::Update(double DeltaTime)
{
}


void Component::FixedUpdate(double Time)
{

}

void Component::SetBaseActor(ActorBase* baseActor)
{
	BaseActor = baseActor;
}

void Component::AddTag(std::string newTag)
{
	_tags.push_back(newTag);
}

void Component::RemoveTag(std::string tagToDelete)
{
	std::vector<std::string>::iterator it = std::find(_tags.begin(), _tags.end(), tagToDelete);
	_tags.erase(it);
}

bool Component::ContainsTag(std::string tagName)
{
	for (std::string v : _tags)
	{
		if (v == tagName)
			return true;
	}

	return false;
}