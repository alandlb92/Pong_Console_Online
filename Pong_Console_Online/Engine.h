#pragma once
#include <iostream>
#include "ActorBase.h"
#include "Shape.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"

class Engine
{
private:
	bool gameIsRunning = true;
	InputSystem* _inputSystem = nullptr;

public:
	~Engine();
	void SetUp(); 
	void UpDate(double DeltaTime);
	const bool IsGameRunning();
};

