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

void Engine::Start(bool isServer)
{
	SetUp(isServer);
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
	if (isServer)
	{
		_inputSystem = new InputSystem(gameIsRunning);
		_graphicsSystem = new GraphicsSystem(Vector2(50, 50));
	}
}

void Engine::UpDate(double DeltaTime)
{
	if (_inputSystem->GetKey("Escape"))
		gameIsRunning = false;

	//Update
	/*for (auto actor : _actors)
	{

	}*/

	//Draw
	if (_graphicsSystem != nullptr)
		_graphicsSystem->Draw(_actors);
}