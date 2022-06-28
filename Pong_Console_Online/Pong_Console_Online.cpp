// Pong_Console_Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ActorBase.h"
#include "Shape.h"
#include "InputSystem.h"
#include <future>

bool gameIsRunning = true;

void Setup()
{
    ActorBase* actor = new ActorBase{};
    Shape* shape = new Shape{ "o" };
    actor->AddComponent(shape);
}

void InputThread()
{ 
    while(gameIsRunning)
    {
        InputSystem::Instance->Update();
    }
}

int main()
{
    InputSystem inputSystem;
    std::cout << "Hello Client!\n";
    std::thread t1(InputThread);
    Setup();

    std::cout << "Game starts\n";
    while (gameIsRunning)
    {
    }

    std::cout << "Good Bye Client!\n";
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
