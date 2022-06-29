#include "GraphicsSystem.h"
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>

GraphicsSystem::GraphicsSystem(Vector2 screenSize)
{
	_screenSize = screenSize;

	/*static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 30;
	fontex.dwFontSize.X = 30;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	SMALL_RECT rect = { 100,100, _screenSize.x, _screenSize.y};
	SetConsoleWindowInfo(hOut, TRUE, &rect);

	DWORD prev_mode;
	GetConsoleMode(hOut, &prev_mode);
	SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));*/
}

const Vector2 GraphicsSystem::GetScreenSize()
{
	return _screenSize;
}

void GraphicsSystem::Draw(std::list<ActorBase*> actors)
{

	//Clear console
	system("CLS");
	//Draw All Shapes
	//std::stringstream ss;
	//for (int y = 0; y < _screenSize.y; y++)
	//{
	//	for (int x = 0; x < _screenSize.x;x++)
	//	{
	//		for (auto a : actors)
	//		{
	//			//If have more than one in the same position
	//			//PositionsOcuped
	//			if ((int)a->transform->position.x == x && (int)a->transform->position.y == y)
	//			{
	//				ss << '*';
	//			}
	//			else
	//			{
	//				ss << ' ';
	//			}
	//		}
	//	}
	//	ss << std::endl;
	//}

	//std::cout << ss.str();
	for (auto a : actors)
	{
		printf("\033[%d;%dH%s\n", (int) a->transform->position.y, (int) a->transform->position.x, " * ");
		printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 1, (int)a->transform->position.x, "***");
		printf("\033[%d;%dH%s\n", (int)a->transform->position.y + 2, (int)a->transform->position.x, " * ");
		//std::goto
		//std::cout << std::goto
	}
	
}