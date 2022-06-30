#pragma once
#include <iostream>
#include <sstream>

struct Vector2
{
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
};
