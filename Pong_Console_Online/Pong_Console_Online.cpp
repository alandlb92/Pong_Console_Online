// Pong_Console_Online.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "ActorBase.h"
#include "Graphic.h"
#include "Component.h"

void PrintScene(Scene* scene)
{
	std::cout << std::endl << std::endl << scene->GetName() << " with " << scene->GetActorNumbers() << " actors" << std::endl;

	for (int i = 0; i < scene->GetActorNumbers(); i++)
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
	_newActor.transform->position = Vector2(10);

	Component comp;
	Graphic graphicComp;

	_newActor.AddComponent(&comp);
	_newActor.AddComponent(&graphicComp);

	ActorBase _newActor2 = ActorBase();
	_newActor2.transform->position = Vector2(50);

	Scene scene = Scene("MainScene");
	scene.AddActor(&_newActor);
	scene.AddActor(&_newActor2);

	Engine _engine;
	_engine.Start(scene, false);
}
