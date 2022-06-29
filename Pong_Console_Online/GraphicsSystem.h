#pragma once
#include "Vector2.h"
#include <list>
#include "ActorBase.h"

class GraphicsSystem
{
public:
	GraphicsSystem(Vector2 screenSize);
	const Vector2 GetScreenSize();

	void Draw(std::list<ActorBase*> actors);

private:
	Vector2 _screenSize;	
};

