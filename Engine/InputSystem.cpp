#include "InputSystem.h"
#include <conio.h>
#include <iostream>
#include <future>
#ifdef _WIN32  || _WIN64
#include <Windows.h>
#else
#include <unistd.h>
#endif
InputSystem::InputSystem(bool& gameIsRunning) : e_gameIsRunning(gameIsRunning)
{
	_inputThread = new std::thread(&InputSystem::InputThread, this);
}

InputSystem::~InputSystem()
{
	_inputThread->join();
}

void InputSystem::InputThread()
{
	while (e_gameIsRunning)
	{
		Update();
	}
}

bool InputSystem::GetKey(const char* keyName)
{
	auto Key = FoundKey(keyName);
	if (Key != keyList.end() && Key->state == KeyState::Holded)
		return true;
	else
		return false;
}

std::list<InputSystem::Key>::iterator InputSystem::FoundKey(const char* keyName)
{
	return std::find_if(keyList.begin(), keyList.end(), [&](Key const& key) {return key.name == keyName; });
}

void InputSystem::Update()
{
	int keyPressed = 0;

	if (_kbhit())
	{
		keyPressed = _getch();
	}

	CalculateCurrentKeyStates(keyPressed);
}

void InputSystem::CalculateCurrentKeyStates(int currentPressed)
{
	for (auto k : keyList)
	{
		auto key = FoundKey(k.name);

		if (key->value == currentPressed)
			key->state = KeyState::Holded;
		else
			key->state = KeyState::Clean;
	}
}

void InputSystem::printKeysStates(std::list<Key> list, const char* tittle)
{
	std::cout << "*************************" << tittle << "****************************" << std::endl;
	std::cout << "{" << std::endl;
	for (auto k : list)
	{
		std::cout << "   {" << std::endl
			<< "      Name: " << k.name << std::endl
			<< "      Value: " << k.value << std::endl
			<< "      State" << k.state << std::endl
			<< "   }," << std::endl;
	}
	std::cout << "}" << std::endl;
	std::cout << "*****************************************************" << std::endl;
}