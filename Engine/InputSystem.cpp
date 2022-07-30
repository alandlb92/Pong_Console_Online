#include "InputSystem.h"
#include <conio.h>
#include <iostream>
#include <future>


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

bool InputSystem::GetKey(KeyCode keyCode)
{
	auto Key = FoundKey(keyCode);
	if (Key != keyList.end() && Key->state == KeyState::Holded)
		return true;
	else
		return false;
}

std::list<InputSystem::Key>::iterator InputSystem::FoundKey(KeyCode keyCode)
{
	return std::find_if(keyList.begin(), keyList.end(), [&](Key const& key) {return key.key == keyCode; });
}

void InputSystem::Update()
{
	CalculateCurrentKeyStates();
	//printKeysStates(keyList, "Input Log");
}

void InputSystem::CalculateCurrentKeyStates()
{
	for (auto k : keyList)
	{		
		auto key = FoundKey(k.key);
		if (GetKeyState(k.value) & 0x8000)		
			key->state = KeyState::Holded;
		else
			key->state = KeyState::Clean;
	}
}

void InputSystem::printKeysStates(std::list<Key> list, const char* tittle)
{
	system("cls");
	std::cout << "*************************" << tittle << "****************************" << std::endl;
	std::cout << "{" << std::endl;
	for (auto k : list)
	{
		std::cout << "   {" << std::endl
			<< "      Name: " << KeyCodeUtils::KeyCodeToString(k.key) << std::endl
			<< "      Value: " << k.value << std::endl
			<< "      State: " << ((k.state == KeyState::Holded) ? "holded" : "Idle") << std::endl
			<< "   }," << std::endl;
	}
	std::cout << "}" << std::endl;
	std::cout << "*****************************************************" << std::endl;

	if(GetKey(KeyCode::UpArrow))
		std::cout << "DO SOMETHING" << std::endl;

}