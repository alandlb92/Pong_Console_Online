// Pong_Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Engine/ActorBase.cpp"
#include "../Engine/Scene.h"
#include "../Engine/Engine.h"
#include "BallActor.h"
#include "ConnectionComponent.h"
#include "Racket.h"
#include "DataReceiver.h"

int main()
{
	std::cout << "version0.1a" << std::endl;	

	Engine _engine;
	
	DataReceiver* _dataReceiver = new DataReceiver();
	ConnectionComponent* _connection = new ConnectionComponent(_engine.gameIsRunning, bind(&DataReceiver::Distribute, _dataReceiver, std::placeholders::_1, std::placeholders::_2));

	BallActor* ball = new BallActor(bind(&ConnectionComponent::UpdateBallPosition, _connection, std::placeholders::_1));
	Racket* racketPlayer1 = new Racket(bind(&ConnectionComponent::UpdateRacketPlayer1Position, _connection, std::placeholders::_1));
	Racket* racketPlayer2 = new Racket(bind(&ConnectionComponent::UpdateRacketPlayer2Position, _connection, std::placeholders::_1));

	racketPlayer1->transform->position.x = 0;
	racketPlayer2->transform->position.x = 25;

	_dataReceiver->Racketplayer1 = racketPlayer1;
	_dataReceiver->Racketplayer2 = racketPlayer2;

	Scene scene = Scene("MainScene");
	scene.AddComponent(_connection);
	scene.AddActor(ball);
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
