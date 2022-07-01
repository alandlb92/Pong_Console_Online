#pragma once
#include "Vector2.h"
#include <list>
#include "ActorBase.h"
#include "Scene.h"

class GraphicsSystem
{

public:
	GraphicsSystem(Vector2 screenSize);
	const Vector2 GetScreenSize();
	void Draw(Scene* scene);

private:
	Vector2 _screenSize;	
};

