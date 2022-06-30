#pragma once
#include "Component.h"

class Shape : public Component
{
private:
	const char* _shape;

public:
	Shape(const char* shape) : _shape(shape) {}
};

