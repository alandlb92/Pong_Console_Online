#pragma once
#include "ActorBase.h"

struct Scene
{
private:
	std::string SceneName;
	ActorBase** Actors = nullptr;
	int numberOfActors = 0;

public:
	Scene(std::string sceneName)
	{
		SceneName = sceneName;
	}

	std::string GetName()
	{
		return SceneName;
	}

	int GetActorNumbers()
	{
		return numberOfActors;
	}

	ActorBase** GetActors()
	{
		return Actors;
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
