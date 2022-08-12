#include "Game.h"
#include "Engine.h"

Game* Game::Instance = nullptr;

InputSystem* Game::GetInputSystem()
{
	return _engine->_inputSystem;
}

Scene* Game::GetCurrentScene()
{
	return _engine->_currentScene;
}

Game* Game::GetInstance()
{
	return Game::Instance;
}