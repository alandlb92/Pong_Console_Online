#include "Engine.h"
#include <windows.h>

Engine::~Engine()
{
	delete _inputSystem;
}

const bool Engine::IsGameRunning()
{
	return gameIsRunning;
}

void Engine::Start(Scene startScene, bool isServer)
{
	_currentScene = &startScene;

	SetUp(isServer);

	if (_currentScene != nullptr)
		for (int i = 0; i < _currentScene->GetActorNumbers(); i++)
		{
			_currentScene->GetActors()[i]->Start();
		}

	auto currentTime = std::chrono::high_resolution_clock::now();
	auto lastTime = std::chrono::high_resolution_clock::now();
	double deltaTime = 0;

	while (IsGameRunning())
	{
		currentTime = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime).count() * 1e-9;
		lastTime = std::chrono::high_resolution_clock::now();
		UpDate(deltaTime);
	}
}

void Engine::SetUp(bool isServer)
{
	if (!isServer)
	{
		_inputSystem = new InputSystem(gameIsRunning);
		_graphicsSystem = new GraphicsSystem(Vector2(25, 50));
	}
}

void Engine::UpDate(double DeltaTime)
{
	if (_inputSystem->GetKey("Escape"))
		gameIsRunning = false;

	//Update
	if(_currentScene != nullptr)
		for (int i = 0;i < _currentScene->GetActorNumbers();i++)
		{
			_currentScene->GetActors()[i]->Update();
		}

	//Draw
	if (_graphicsSystem != nullptr)
		_graphicsSystem->Draw(_currentScene);
}