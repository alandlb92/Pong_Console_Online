#pragma once
#include <iostream>
#include "ActorBase.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "Scene.h"
#include "Game.h"

class Engine
{
private:
	InputSystem* _inputSystem = nullptr;
	GraphicsSystem* _graphicsSystem = nullptr;
	ActorBase** _actors = nullptr;
	Scene* _currentScene = nullptr;
	Game* _world;


	void SetUp(bool isServer);
	void UpDate(double DeltaTime);

public:
	Engine() : _world(new Game(this)) {}
	~Engine();
	bool gameIsRunning = true;
	void Start(Scene startScene ,bool isServer);
	InputSystem* GetInputSystem();
};

