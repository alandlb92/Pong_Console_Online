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


void Engine::SetUp()
{
    _inputSystem = new InputSystem(gameIsRunning);    
    _graphicsSystem = new GraphicsSystem(Vector2(50, 10));

    actorTest = new ActorBase();
    Shape* shape = new Shape{ "*" };
    actorTest->AddComponent(shape);
    _actors.push_back(actorTest);
}

void Engine::UpDate(double DeltaTime)
{
    if (_inputSystem->GetKey("Escape"))
        gameIsRunning = false;

    //Update
    actorTest->transform->position.x += (50 * DeltaTime);
    if (actorTest->transform->position.x > _graphicsSystem->GetScreenSize().x)
    {
        actorTest->transform->position.x = 0;
        actorTest->transform->position.y++;
       // Beep(600, 150);
    }

    //Draw
    _graphicsSystem->Draw(_actors);
}