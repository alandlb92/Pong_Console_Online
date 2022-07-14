#pragma once
#include <iostream>
#include "ActorBase.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "Scene.h"

class Engine
{
private:
	InputSystem* _inputSystem = nullptr;
	GraphicsSystem* _graphicsSystem = nullptr;
	ActorBase** _actors;
	Scene* _currentScene;

	void SetUp(bool isServer);
	void UpDate(double DeltaTime);

public:
	~Engine();
	bool gameIsRunning = true;
	void Start(Scene startScene ,bool isServer);
};

