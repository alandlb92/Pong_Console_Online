#pragma once
#include <iostream>
#include <vector>

class Component
{
	friend class ActorBase;

private:
	std::vector<std::string> _tags;
	void SetBaseActor(class ActorBase* baseActor);

protected:
	bool _isPhysicsComponent = false;
	class ActorBase* BaseActor;

public:
	virtual void Start();
	virtual void Update(double DeltaTime);
	virtual void FixedUpdate(double DeltaTime);


	void AddTag(std::string newTag);
	void RemoveTag(std::string tagToDelete);
	bool ContainsTag(std::string tagName);

	bool IsPhysicsComponent() { return _isPhysicsComponent; };
};

