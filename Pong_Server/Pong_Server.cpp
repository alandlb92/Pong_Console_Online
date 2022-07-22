// Pong_Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Engine/ActorBase.cpp"
#include "../Engine/Scene.h"
#include "../Engine/Engine.h"
#include "BallActor.h"
#include "ConnectionComponent.h"

int main()
{
	std::cout << "version0.1a" << std::endl;	

	Engine _engine;
	
	ConnectionComponent* _connection = new ConnectionComponent(_engine.gameIsRunning);
	//BallActor* ball = new BallActor(bind(&ConnectionComponent::UpdateBallPosition, _connection, std::placeholders::_1));

	Scene scene = Scene("MainScene");
	scene.AddComponent(_connection);
	//scene.AddActor(ball);
	_engine.Start(scene, true);
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
