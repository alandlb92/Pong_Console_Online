#include "GraphicsSystem.h"
#include <stdlib.h>
#include<stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include "Graphic.h"

GraphicsSystem::GraphicsSystem(Vector2 screenSize, bool& gameIsRunning, Scene& currentScene) : e_gameIsRunning(gameIsRunning), _currentScene(currentScene)
{
	_screenSize = screenSize;
	_graphicsThread = new std::thread(&GraphicsSystem::GraphicsThread, this);

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
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	DWORD prev_mode;

	HANDLE hInput;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	//SMALL_RECT rect = { 100,100, _screenSize.x, _screenSize.y};
	//SetConsoleWindowInfo(hOut, TRUE, &rect);

	//DWORD prev_mode;
	//GetConsoleMode(hOut, &prev_mode);
	//SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS |
	//	(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

GraphicsSystem::~GraphicsSystem()
{
	_graphicsThread->join();
}

void GraphicsSystem::GraphicsThread()
{
	while (e_gameIsRunning)
	{
		//make some delay
		Sleep(DrawnDelayMS);
		if (e_gameIsRunning)
			Draw();
	}
}

const Vector2 GraphicsSystem::GetScreenSize()
{
	return _screenSize;
}

void GraphicsSystem::Draw()
{
	//Clear console
	system("CLS");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	for (int i = 0; i < _currentScene.GetActorCount(); i++)
	{
		ActorBase* Actor = _currentScene.GetActors()[i];

		for (auto g : Actor->GetComponents<Graphic>())
		{
			Image* image = g->GetImage();
			int counter = 0;
			int Height = image->GetHeight();
			int Width = image->GetWidth();

			for (int j = 0; j < Height; j++)
			{
				int offset = 0;
				for (int k = 0; k < Width; k++)
				{
					Form* form = image->GetImageForm()[counter];
					SetConsoleTextAttribute(h, form->wordAtributes);
					printf("\033[%d;%dH%s\n", (int)Actor->transform->position.y + j, (int)Actor->transform->position.x + k + offset, form->form.c_str());
					counter++;
					offset += (int)(form->form.size() - 1);
				}
			}
		}
	}
	SetConsoleTextAttribute(h, 15);
}