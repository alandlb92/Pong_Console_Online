#pragma once
#include "Component.h"
#include "Image.h"

class Graphic : public Component
{
public:
	Graphic(Image image) : _image(&image) {}

	typedef Component super;

	virtual void Start();
	virtual void Update(double DeltaTime);
	Image* GetImage();

private:
	Image* _image;

};

