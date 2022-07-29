#pragma once
#include "Component.h"
#include <iostream>
#include <functional>
#include "InputState.h"

class PlayerInputComponent : public Component
{
private:
	typedef Component super;
	std::function<void(InputState)> OnInputChanged;
	InputState _currentInputState = InputState::Idle;

	void SetInput(InputState state);

public:
	PlayerInputComponent(std::function<void(InputState)> _OnInputChanged)
		: OnInputChanged(_OnInputChanged) {};
	void Update(double DeltaTime) override;

};

