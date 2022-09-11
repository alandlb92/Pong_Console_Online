#pragma once
#include "Vector2.h"
#include <list>
#include "ActorBase.h"
#include "Scene.h"
#include <future>


class GraphicsSystem
{

public:
	GraphicsSystem(Vector2 screenSize, float margin, bool& gameIsRunning, Scene& scene);
	~GraphicsSystem();
	const Vector2 GetScreenSize();
	void Draw();

private:
	const int fps = 30;
	const bool DrawBorder = true;
	int _marginVertical;
	int _marginHorizontal;
	bool& e_gameIsRunning;
	Scene& _currentScene;
	void cls(HANDLE hConsole);

	std::thread* _graphicsThread = nullptr;
	void GraphicsThread();
	Vector2 _screenSize;
};

