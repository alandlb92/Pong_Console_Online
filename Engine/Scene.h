#pragma once
#include "ActorBase.h"

class Scene
{
private:
	std::string SceneName;
	Component** _components = nullptr;
	ActorBase** Actors = nullptr;
	int numberOfActors = 0;
	int numberOfComponent = 0;

public:
	Scene(std::string sceneName)
	{
		SceneName = sceneName;
	}


	std::string GetName()
	{
		return SceneName;
	}

	int GetComponentsCount()
	{
		return numberOfComponent;
	}

	int GetActorCount()
	{
		return numberOfActors;
	}

	Component** GetComponents()
	{
		return _components;
	}

	ActorBase** GetActors()
	{
		return Actors;
	}

	void AddComponent(Component* component)
	{
		Component** copy = (Component**)realloc(_components, (numberOfComponent + 1) * sizeof(Component*));
		if (copy == NULL)
			return;

		_components = copy;		
		_components[numberOfComponent] = component;
		numberOfComponent++;
	}

	void AddActor(ActorBase* actor)
	{
		ActorBase** copy = (ActorBase**)realloc(Actors, (numberOfActors + 1) * sizeof(ActorBase*));
		if (copy == NULL)
			return;

		Actors = copy;
		Actors[numberOfActors] = actor;
		numberOfActors++;
	}

	void DeleteActor(ActorBase* actor)
	{
		int indexToDelete = -1;
		for (int i = 0; i < numberOfActors; i++)
		{
			if (Actors[i] == actor) {
				indexToDelete = i;
				break;
			}
		}

		if (indexToDelete != numberOfActors - 1) {
			Actors[indexToDelete] = Actors[numberOfActors - 1];
			Actors[numberOfActors - 1] = nullptr;
		}

		numberOfActors--;
		ActorBase** copy = (ActorBase**)realloc(Actors, (numberOfActors) * sizeof(ActorBase*));
		if (copy == NULL)
			return;

		Actors = copy;
	}
};
