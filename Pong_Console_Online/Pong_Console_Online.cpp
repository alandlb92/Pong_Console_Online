// Pong_Console_Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "ActorBase.h"
#include "Graphic.h"
#include "Component.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

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
	ActorBase _newActor = ActorBase();
	_newActor.transform->position = Vector2(10, 2);
									 
	Form form[] =   { Form(255, "  ")};

	Graphic graphicComp = Graphic(Image::CreateImage(form, 1, 1));

	_newActor.AddComponent(&graphicComp);

	ActorBase _newActor2 = ActorBase();
	_newActor2.transform->position = Vector2(10);

	Scene scene = Scene("MainScene");
	scene.AddActor(&_newActor);
	scene.AddActor(&_newActor2);

	Engine _engine;
	_engine.Start(scene, false);
}
