#pragma once
class Game
{
private:
	class Engine* _engine;
	static Game* Instance;

public:	
	Game(Engine* engine) : _engine(engine) {
		if (Instance == nullptr) {
			Instance = this;
		}
	};

	static Game* GetInstance();

	class InputSystem* GetInputSystem();
};

