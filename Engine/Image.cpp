#include "Image.h"

Image Image::CreateImage(Form colors[], int Width, int Height)
{
	Image newImage = Image();
	newImage.Width = Width;
	newImage.Height = Height;

	newImage._Form = (Form**) calloc(Width * Height, sizeof(Form));

	if(newImage._Form != nullptr)
		for (int i = 0; i < Width * Height; i++)
		{
			newImage._Form[i] = &colors[i];
		}
	return newImage;
}

int Image::GetTotalSize()
{
	return Height * Width;
}

int Image::GetHeight()
{
	return Height;
}

int Image::GetWidth()
{
	return Width;
}

Form** Image::GetImageForm()
{
	return _Form;
}