#pragma once
#include <map>
#include <list>

class InputSystem
{
public:
	static InputSystem* Instance;
	enum KeyState
	{
		Pressed,
		Released,
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
		{"AnyArrow", 224, KeyState::Clean},
		{"Arrow_Up", 72, KeyState::Clean},
		{"Arrow_Down", 80, KeyState::Clean},
		{"Arrow_Right", 77, KeyState::Clean},
		{"Arrow_Left", 75, KeyState::Clean},
		{"Escape", 27, KeyState::Clean}
	};

	InputSystem();
	void Update();

private:
	std::map<Key, KeyState> keyStates;

	void printKeysStates(std::list<Key> list, const char* tittle);
	std::list<InputSystem::Key>  CopyKeyListState();
	void CleanKeyState();
};

