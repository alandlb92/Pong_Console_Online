#pragma once
#include <iostream>
#include "ActorBase.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include "Scene.h"
#include "Game.h"
#include "PhysicsSystem.h"
#include "Game.h"

class Engine
{
	friend class Game;
private:
	Vector2 _screenSize;
	float _margin;
	InputSystem* _inputSystem = nullptr;
	GraphicsSystem* _graphicsSystem = nullptr;
	PhysicsSystem* _physicsSystem = nullptr;

	ActorBase** _actors = nullptr;
	Scene* _currentScene = nullptr;
	Game* _world;


	void SetUp(bool isServer);
	void UpDate(double DeltaTime);

public:
	Engine(Vector2 screenSize, float margin) : _world(new Game(this)), _screenSize(screenSize), _margin(margin) {
		
	}
	~Engine();
	bool gameIsRunning = false;
	void Start(Scene startScene ,bool isServer);
};

