#pragma once
#include "Vector2.h"
#include <list>
#include "ActorBase.h"
#include "Scene.h"
#include <future>


class GraphicsSystem
{

public:
	GraphicsSystem(Vector2 screenSize, bool& gameIsRunning, Scene& scene);
	~GraphicsSystem();
	const Vector2 GetScreenSize();
	void Draw();

private:
	const int DrawnDelayMS = 100;
	bool& e_gameIsRunning;
	Scene& _currentScene;

	std::thread* _graphicsThread = nullptr;
	void GraphicsThread();
	Vector2 _screenSize;
};

