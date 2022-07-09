#include "GraphicsSystem.h"
#include <stdlib.h>
#include<stdlib.h>
#include <Windows.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include "Graphic.h"

GraphicsSystem::GraphicsSystem(Vector2 screenSize)
{
	_screenSize = screenSize;

	std::stringstream ss;
	ss << "MODE CON COLS=" << (int)screenSize.y << " LINES=" << (int)screenSize.x;
	system(ss.str().c_str());

	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 300;
	COORD size;
	size.X = 10;
	size.Y = 10;
	fontex.dwFontSize = size;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	//SMALL_RECT rect = { 100,100, _screenSize.x, _screenSize.y};
	//SetConsoleWindowInfo(hOut, TRUE, &rect);

	//DWORD prev_mode;
	//GetConsoleMode(hOut, &prev_mode);
	//SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS |
	//	(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

const Vector2 GraphicsSystem::GetScreenSize()
{
	return _screenSize;
}

void GraphicsSystem::Draw(Scene* scene)
{

	//Clear console
	system("CLS");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	for (int i = 0; i < scene->GetActorNumbers(); i++)
	{
		ActorBase* Actor = scene->GetActors()[i];
		for (auto g : Actor->GetComponents<Graphic>())
		{
			Image* image = g->GetImage();
			int counter = 0;
			for (int j = 0; j < image->GetHeight(); j++)
			{
				int offset = 0;
				for (int k = 0; k < image->GetWidth(); k++)
				{
					Form* form = image->GetImageForm()[counter];
					SetConsoleTextAttribute(h, form->wordAtributes);
					printf("\033[%d;%dH%s\n", (int)Actor->transform->position.y + j, (int)Actor->transform->position.x + k + offset, form->form.c_str());
					counter++;
					offset += (form->form.size() - 1);
				}
			}		
		}
	}
	SetConsoleTextAttribute(h, 15);
}