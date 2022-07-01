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
	//system("CLS");
	for (int i = 0; i < scene->GetActorNumbers(); i++)
	{
		for (auto g: scene->GetActors()[i]->GetComponents<Graphic>())
		{
			std::cout << "Draw Actor-> " << i << " Position-> " << scene->GetActors()[i]->transform->position.toString() << std::endl;

			/*HANDLE h;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y, (int)a->transform->position.x, "  ");
			SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y, (int)a->transform->position.x + 2, "  ");
			SetConsoleTextAttribute(h, 15);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y, (int)a->transform->position.x + 4, "  ");

			SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 1, (int)a->transform->position.x, "      ");


			SetConsoleTextAttribute(h, 15);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 2, (int)a->transform->position.x, "  ");
			SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 2, (int)a->transform->position.x + 2, "  ");
			SetConsoleTextAttribute(h, 15);
			printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 2, (int)a->transform->position.x + 4, "  ");*/
		}
	}
}