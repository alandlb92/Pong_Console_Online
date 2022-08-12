#pragma once
#include <iostream>
#include "Form.h"
#include "Vector2.h"

class Image
{
public:
	static Image CreateImage(Form colors[], int Width, int Height);
	int GetHeight();
	int GetWidth();
	Form** GetImageForm();
	int GetTotalSize();

private:
	int Height;
	int Width;
	Form** _Form;

};

