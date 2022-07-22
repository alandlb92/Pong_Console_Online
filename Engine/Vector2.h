#pragma once
#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

class Vector2
{
public:
	float x;
	float y;

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	Vector2(float _xy)
	{
		x = _xy;
		y = _xy;
	}

	std::string toString()
	{
		std::stringstream ss;
		ss << "x: " << x << " y: " << y << std::endl;
		return ss.str();
	}
private:
	friend class boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive& ar, Vector2& a, const unsigned int version)
	{
		ar& a.x;
		ar& a.y;
	}
};
