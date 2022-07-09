#pragma once

#include "Color.h";
#include <iostream>

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

