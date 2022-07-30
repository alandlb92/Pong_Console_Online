#include "Engine.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

Engine::~Engine()
{
	delete _inputSystem;
}

void Engine::Start(Scene startScene, bool isServer)
{

	_currentScene = &startScene;

	SetUp(isServer);


	//Start Components and Actors
	if (_currentScene != nullptr)
	{
		for (int i = 0; i < _currentScene->GetComponentsCount(); i++)
		{
			_currentScene->GetComponents()[i]->Start();
		}

		for (int i = 0; i < _currentScene->GetActorCount(); i++)
		{
			_currentScene->GetActors()[i]->Start();
		}
	}

	auto currentTime = std::chrono::high_resolution_clock::now();
	auto lastTime = std::chrono::high_resolution_clock::now();
	double deltaTime = 0;

	while (gameIsRunning)
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
	//Update
	if (_currentScene != nullptr) 
	{
		for (int i = 0; i < _currentScene->GetComponentsCount(); i++)
		{
			_currentScene->GetComponents()[i]->Update(DeltaTime);
		}

		for (int i = 0;i < _currentScene->GetActorCount();i++)
		{
			_currentScene->GetActors()[i]->Update(DeltaTime);
		}
	}

	//Draw
	if (_graphicsSystem != nullptr)
		_graphicsSystem->Draw(_currentScene);
}


InputSystem* Engine::GetInputSystem()
{
	return _inputSystem;
}