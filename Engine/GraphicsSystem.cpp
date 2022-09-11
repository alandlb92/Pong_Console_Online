#include "GraphicsSystem.h"
#include <stdlib.h>
#include<stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include "Graphic.h"

GraphicsSystem::GraphicsSystem(Vector2 screenSize, float margin, bool& gameIsRunning, Scene& currentScene) : e_gameIsRunning(gameIsRunning), _currentScene(currentScene)
{
	_marginHorizontal = margin;
	_marginVertical = margin/2;
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
		Sleep(1000/fps);
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
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	cls(h);

	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	if (DrawBorder)
	{
		SetConsoleTextAttribute(h, 15);
		int firstScreenPositionVerticalForBorder = _marginVertical - 1;
		int firstScreenPositionHorizontalForBorder = _marginHorizontal - 1;

		int lastScreenPositionVerticalForBorder = _marginVertical + _screenSize.y + 1;
		int lastScreenPositionHorizontalForBorder = _marginHorizontal + _screenSize.x + 1;


		COORD coord = { 0,0 };
		SetConsoleCursorPosition(hConsole, coord);

		char* arr;
		for (int i = firstScreenPositionVerticalForBorder; i <= lastScreenPositionVerticalForBorder; i++)
			for (int i = firstScreenPositionHorizontalForBorder; i <= lastScreenPositionHorizontalForBorder; i++)
				
		/*for (int i = firstScreenPositionVerticalForBorder; i <= lastScreenPositionVerticalForBorder; i++)
		{
			printf("\033[%d;%dH%s\r", i, firstScreenPositionHorizontalForBorder, "*");
			printf("\033[%d;%dH%s\r", i, lastScreenPositionHorizontalForBorder, "*");
		}

		for (int i = firstScreenPositionHorizontalForBorder; i <= lastScreenPositionHorizontalForBorder; i++)
		{
			printf("\033[%d;%dH%s\r", firstScreenPositionVerticalForBorder, i, "*");
			printf("\033[%d;%dH%s\r", lastScreenPositionVerticalForBorder, i, "*");
		}*/
		puts(arr);
	}


	//for (int i = 0; i < _currentScene.GetActorCount(); i++)
	//{
	//	ActorBase* Actor = _currentScene.GetActors()[i];

	//	for (auto g : Actor->GetComponents<Graphic>())
	//	{
	//		Image* image = g->GetImage();
	//		int counter = 0;
	//		int Height = image->GetHeight();
	//		int Width = image->GetWidth();

	//		for (int j = 0; j < Height; j++)
	//		{
	//			int offset = 0;
	//			for (int k = 0; k < Width; k++)
	//			{
	//				Form* form = image->GetImageForm()[counter];
	//				SetConsoleTextAttribute(h, form->wordAtributes);
	//				printf("\033[%d;%dH%s\r", (int)Actor->transform->position.y + j + _marginVertical, (int)Actor->transform->position.x + k + offset + _marginHorizontal, form->form.c_str());
	//				counter++;
	//				offset += (int)(form->form.size() - 1);
	//			}
	//		}
	//	}
	//}
	SetConsoleTextAttribute(h, 15);
}

void GraphicsSystem::cls(HANDLE hOut)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}