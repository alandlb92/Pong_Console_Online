#pragma once
#include <map>
#include <list>
#include <future>
#include "KeyState.h"
#include "KeyCode.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class InputSystem
{
public:
	InputSystem(bool& gameIsRunning);
	~InputSystem();
	bool GetKey(KeyCode keyCode);

private:
	bool& e_gameIsRunning;
	std::thread* _inputThread = nullptr;
	void InputThread();
	void Update();

	struct Key
	{
		KeyCode key;
		const int value;
		KeyState state;
	};

	std::list<Key> keyList
	{
		{KeyCode::UpArrow, VK_UP, KeyState::Clean},
		{KeyCode::DownArrow, VK_DOWN, KeyState::Clean},
		{KeyCode::RightArrow, VK_RIGHT, KeyState::Clean},
		{KeyCode::LeftArrow, VK_LEFT, KeyState::Clean},
		{KeyCode::Escape, VK_ESCAPE, KeyState::Clean}
	};
	std::map<Key, KeyState> keyStates;
	void printKeysStates(std::list<Key> list, const char* tittle);
	void CalculateCurrentKeyStates();
	std::list<Key>::iterator FoundKey(KeyCode keyCode);
};

