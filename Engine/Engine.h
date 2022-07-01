#pragma once
#include <iostream>
#include "ActorBase.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "Scene.h"

class Engine
{
private:
	bool gameIsRunning = true;
	InputSystem* _inputSystem = nullptr;
	GraphicsSystem* _graphicsSystem = nullptr;
	ActorBase** _actors;
	Scene* _currentScene;

	void SetUp(bool isServer);
	void UpDate(double DeltaTime);

public:
	~Engine();
	void Start(Scene startScene ,bool isServer);
	const bool IsGameRunning();
};

