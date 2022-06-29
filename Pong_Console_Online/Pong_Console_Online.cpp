// Pong_Console_Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include <chrono>

Engine* _engine = nullptr;


int main()
{
    std::cout << "Hello Client!\n";
    _engine = new Engine;
    _engine->SetUp();
    std::cout << "Game starts\n";
    
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto lastTime = std::chrono::high_resolution_clock::now();
    double deltaTime = 0;

    while (_engine->IsGameRunning())
    {
        currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime).count() * 1e-9;
        _engine->UpDate(deltaTime);
        lastTime = std::chrono::high_resolution_clock::now();
    }

    std::cout << "Game is ending\n";
    delete _engine;
    std::cout << "Good Bye Client!\n";
}