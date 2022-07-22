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

	////Enter Server Path
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
		////Connect With Server
		std::cout << "Server not found" << std::endl;
		return 0;
	}


	////Connect With Server
	std::cout << "Server Connected :)" << std::endl;
	std::cout << "Enter your name:" << std::endl;
	std::cin >> name;

	Engine _engine;
	Scene scene = Scene("MainScene");
	DataReceiver* _dataReceiver = new DataReceiver;
	BallActor* _ballActor = new BallActor;
	Image _ballImage = Image::CreateImage({ new Form(0, "O") }, 1, 1);
	Graphic* _ballGraphic = new Graphic(_ballImage);
	
	netComp->OnReceiveData = bind(&DataReceiver::Distribute, _dataReceiver, std::placeholders::_1);
	netComp->SetUpClientData(name);

	_ballActor->AddComponent(_ballGraphic);

	_dataReceiver->SetBallPosition = bind(&BallActor::SetPosition, _ballActor, std::placeholders::_1);

	scene.AddComponent(netComp);

	_engine.Start(scene, false);
}
