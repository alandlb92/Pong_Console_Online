#pragma once
#include <iostream>
#include "Vector2.h"
#include "GameState.h"
#include "InputState.h"

struct ServerData
{
public:
	Vector2 BallPosition;
	Vector2 Player1Position;
	Vector2 Player2Position;
	GameState GameState;
	InputState InputState;
};