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

	Engine _engine = Engine(Vector2(150, 75), 30);
	
	DataReceiver* _dataReceiver = new DataReceiver();
	
	ConnectionComponent* _connection = new ConnectionComponent(_engine.gameIsRunning, bind(&DataReceiver::Distribute, _dataReceiver, std::placeholders::_1, std::placeholders::_2));


	BallActor* ball = new BallActor(bind(&ConnectionComponent::UpdateBallPosition, _connection, std::placeholders::_1));
	Racket* racketPlayer1 = new Racket(bind(&ConnectionComponent::UpdateRacketPlayer1Position, _connection, std::placeholders::_1));
	Racket* racketPlayer2 = new Racket(bind(&ConnectionComponent::UpdateRacketPlayer2Position, _connection, std::placeholders::_1));

	racketPlayer1->transform->position.x = 0;
	racketPlayer2->transform->position.x = 100;

	_dataReceiver->Racketplayer1 = racketPlayer1;
	_dataReceiver->Racketplayer2 = racketPlayer2;

	Scene scene = Scene("MainScene");

	scene.AddComponent(_connection);

	scene.AddActor(ball);
	scene.AddActor(racketPlayer1);
	scene.AddActor(racketPlayer2);	
	
	_engine.Start(scene, true);
}
