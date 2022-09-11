// Pong_Console_Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "ActorBase.h"
#include "Graphic.h"
#include "Component.h"
#include "ClientConnectionComponent.h"
#include "DataReceiver.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "BallActor.h"
#include "PlayerInputComponent.h"
#include "RacketActor.h"

void PrintScene(Scene* scene)
{
	std::cout << std::endl << std::endl << scene->GetName() << " with " << scene->GetActorCount() << " actors" << std::endl;

	for (int i = 0; i < scene->GetActorCount(); i++)
	{
		if (scene->GetActors()[i] == nullptr)
		{
			std::cout << "NULL" << std::endl;
		}
		else
			std::cout << "Actor index: " << i << " position: " << scene->GetActors()[i]->transform->position.toString();
	}
}


int main()
{
	std::cout << "Client version 0.1a" << std::endl << std::endl;
	std::string serverIp;
	int port;
	std::string name;

	//Enter Server Path
	std::cout << "Enter the server ip and server port:" << std::endl;
	std::cin >> serverIp;
	std::cin >> port;
	ClientConnectionComponent* netComp;

	try
	{
		netComp = new ClientConnectionComponent(serverIp, port);
	}
	catch (const std::exception&)
	{
		//Connect With Server
		std::cout << "Server not found" << std::endl;
		return 0;
	}


	//Connect With Server
	std::cout << "Server Connected :)" << std::endl;
	std::cout << "Enter your name:" << std::endl;
	std::cin >> name;

	Engine* _engine = new Engine(Vector2(150, 75), 30);
	Scene scene = Scene("MainScene");
	DataReceiver* _dataReceiver = new DataReceiver;
	PlayerInputComponent* _playerInput = new PlayerInputComponent(bind(&ClientConnectionComponent::SetPlayerInput, netComp, std::placeholders::_1));

	BallActor* _ballActor = new BallActor;
	Form ballForm[1] = {{15, "O"}};
	Image _ballImage = Image::CreateImage(ballForm, 1, 1);
	Graphic* _ballGraphic = new Graphic(_ballImage);

	RacketActor* _racketActor1 = new RacketActor();
	RacketActor* _racketActor2 = new RacketActor();

	Form racketForm[3] = {{15,"|"},{15,"|"}, {15,"|"}};
	Image _racketImage = Image::CreateImage(racketForm, 1, 3);
	Graphic* _racketForm = new Graphic(_racketImage);

	_racketActor1->AddComponent(_racketForm);
	_racketActor2->AddComponent(_racketForm);

	netComp->OnReceiveData = bind(&DataReceiver::Distribute, _dataReceiver, std::placeholders::_1);
	netComp->SetUpClientData(name);

	_ballActor->AddComponent(_ballGraphic);

	_dataReceiver->SetBallPosition = bind(&BallActor::SetPosition, _ballActor, std::placeholders::_1);
	_dataReceiver->SetRacketplayer1Position = bind(&RacketActor::SetPosition, _racketActor1, std::placeholders::_1);
	_dataReceiver->SetRacketplayer2Position = bind(&RacketActor::SetPosition, _racketActor2, std::placeholders::_1);

	scene.AddComponent(netComp);
	scene.AddComponent(_playerInput);
	scene.AddActor(_ballActor);
	scene.AddActor(_racketActor1);
	scene.AddActor(_racketActor2);

	_engine->Start(scene, false);
}
