#include "Game.h"
#include "Engine.h"

Game* Game::Instance = nullptr;

InputSystem* Game::GetInputSystem()
{
	return _engine->GetInputSystem();
}


Game* Game::GetInstance()
{
	return Game::Instance;
}