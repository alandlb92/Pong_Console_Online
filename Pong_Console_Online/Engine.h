#pragma once
#include <iostream>
#include "ActorBase.h"
#include "Shape.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "Vector2.h"

class Engine
{
private:
	bool gameIsRunning = true;
	InputSystem* _inputSystem = nullptr;
	GraphicsSystem* _graphicsSystem = nullptr;
	ActorBase* actorTest = nullptr;
	std::list<ActorBase*> _actors;

public:
	~Engine();
	void SetUp(); 
	void UpDate(double DeltaTime);
	const bool IsGameRunning();
};

