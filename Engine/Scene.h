#pragma once
#include "ActorBase.h"

struct Scene
{
	std::string SceneName;
	ActorBase** Actors;
	int numberOfActors = 0;

	void AddActor(ActorBase* actor)
	{
		Actors = (ActorBase**)realloc(Actors, sizeof(ActorBase) * numberOfActors);
		Actors[numberOfActors] = actor;
		numberOfActors++;
	}

	void DeleteActor(ActorBase* actor)
	{
		delete actor;
		actor = nullptr;

		int emptyIndex = -1;
		for (int i = 0; i < numberOfActors; i++)
		{
			if (Actors[i] == nullptr)
				emptyIndex = i;
		}

		if (emptyIndex != numberOfActors - 1) {
			Actors[emptyIndex] = Actors[numberOfActors - 1];
			Actors[emptyIndex] = nullptr;
		}
		numberOfActors--;
		Actors = (ActorBase**)realloc(Actors, sizeof(ActorBase) * numberOfActors);
	}
};
