#pragma once
#include <iostream>
#include "Vector2.h"
#include "GameState.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

class ServerData
{
public:
	Vector2 BallPosition;
	Vector2 RacketPlayer1Position;
	Vector2 RacketPlayer2Position;
	GameState GameState;
private:
	friend class boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive& ar, ServerData& a, const unsigned int version)
	{
		ar& a.BallPosition;
		ar& a.RacketPlayer1Position;
		ar& a.RacketPlayer2Position;
		ar& a.RacketPlayer1Position;
		ar& a.GameState;
	}
};