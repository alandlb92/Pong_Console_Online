#include "Engine.h"

Engine::~Engine()
{
    delete _inputSystem;
}

const bool Engine::IsGameRunning()
{
    return gameIsRunning;
}


void Engine::SetUp()
{
    _inputSystem = new InputSystem(gameIsRunning);
    
    GraphicsSystem graphicsSystem;

    ActorBase* actor = new ActorBase{};
    Shape* shape = new Shape{ "o" };
    actor->AddComponent(shape);
}

void Engine::UpDate(double DeltaTime)
{
    if (_inputSystem->GetKey("Escape"))
        gameIsRunning = false;


}