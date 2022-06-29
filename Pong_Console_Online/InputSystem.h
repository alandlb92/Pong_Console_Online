#pragma once
#include <map>
#include <list>
#include <future>

class InputSystem
{
public:
	InputSystem(bool& gameIsRunning);
	~InputSystem();
	bool GetKey(const char* keyName);

private:
	bool& e_gameIsRunning;
	std::thread* _inputThread = nullptr;
	void InputThread();
	void Update();

	enum KeyState
	{
		Holded,
		Clean
	};
	struct Key
	{
		const char* name;
		const int value;
		KeyState state;
	};

	std::list<Key> keyList
	{
		//{"AnyArrow", 224, KeyState::Clean},
		{"Arrow_Up", 72, KeyState::Clean},
		{"Arrow_Down", 80, KeyState::Clean},
		{"Arrow_Right", 77, KeyState::Clean},
		{"Arrow_Left", 75, KeyState::Clean},
		{"Escape", 27, KeyState::Clean}
	};
	std::map<Key, KeyState> keyStates;
	void printKeysStates(std::list<Key> list, const char* tittle);
	void CalculateCurrentKeyStates(int currentPressed);
	std::list<Key>::iterator FoundKey(const char* keyName);
};

