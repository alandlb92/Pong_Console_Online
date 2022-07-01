#pragma once
#include "Component.h"
#include "Color.h"

class Graphic : public Component
{
public:
	typedef Component super;

	virtual void Start();
	virtual void UpDate();
	Graphic() : _color(new Color) {};
	Graphic(Color* color) : _color(color) {}
	Color* GetShape();

private:
	Color* _color;

};

