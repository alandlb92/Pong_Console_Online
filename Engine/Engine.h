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
	ActorBase** _actors;
	void SetUp(bool isServer);
	void UpDate(double DeltaTime);

public:
	~Engine();
	void Start(bool isServer);
	const bool IsGameRunning();
};

