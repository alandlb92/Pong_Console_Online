#pragma once
#include "Component.h"
#include "Image.h"

class Graphic : public Component
{
public:
	typedef Component super;

	virtual void Start();
	virtual void UpDate();
	Graphic(Image image) : _image(&image) {}
	Image* GetImage();

private:
	Image* _image;

};

