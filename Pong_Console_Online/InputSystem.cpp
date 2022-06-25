#include "InputSystem.h"
#include <conio.h>
#include <iostream>
#include <future>
#ifdef _WIN32  || _WIN64
#include <Windows.h>
#else
#include <unistd.h>
#endif

InputSystem* InputSystem::Instance = nullptr;

InputSystem::InputSystem()
{
	if (InputSystem::Instance == nullptr) {
		InputSystem::Instance = this;
	}
	else
		delete this;
}

void InputSystem::Update()
{
	std::cout << "input update " << std::endl;

	std::list<Key> oldKeyStates = CopyKeyListState();
	CleanKeyState();

	if (_kbhit())
	{
		int keyValue = _getch();
		auto foundKey = std::find_if(keyList.begin(), keyList.end(), [&](Key const& key) {return key.value == keyValue; });

		if (foundKey != keyList.end())
		{
			foundKey->state = KeyState::Pressed;
		}
		else
			std::cout << "Key dosent registered: int " << keyValue << std::endl;
	}
	//Calculate the input state HOLD, PRESSED, RELEASED, CLEAN
	/*printKeysStates(oldKeyStates, "oldKeyStates");
	printKeysStates(keyList, "keyList");*/
	Sleep(100);
}

void InputSystem::CleanKeyState()
{
	for (auto k : keyList)
	{
		k.state = KeyState::Clean;
	}
}

std::list<InputSystem::Key>  InputSystem::CopyKeyListState()
{
	std::list<Key> oldKeyStates;
	for (auto k : keyList)
	{
		Key newKey = Key(k);
		oldKeyStates.push_back(newKey);
	}
	return oldKeyStates;
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