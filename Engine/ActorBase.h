#pragma once
#include <iostream>
#include <vector>
#include "Component.h"
#include "Graphic.h"
#include "Transform.h"

class ActorBase
{
private:
	Component** _components = nullptr;
	int _componentsCount;

public:
	template<class T>
	std::vector<T*> GetComponents() {
		std::vector<T*> result;
		for (int i = 0; i < _componentsCount; i++)
		{
			T* toAdd = nullptr;
			toAdd = dynamic_cast<T*>(_components[i]);
			if (toAdd)
				result.push_back(toAdd);
		}
		return result;
	}

	ActorBase();

	Transform* transform;
	void AddComponent(Component* component);

	virtual void Start();
	virtual void Update(double DeltaTime);

};

