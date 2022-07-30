#include "PlayerInputComponent.h"
#include "Game.h"
#include "InputSystem.h"

void PlayerInputComponent::Start()
{
	super::Start();
}

void PlayerInputComponent::Update(double DeltaTime)
{
	
	super::Update(DeltaTime);
	if (Game::GetInstance()->GetInputSystem()->GetKey(KeyCode::UpArrow))
		SetInput(InputState::Up_Arrow);
	else if (Game::GetInstance()->GetInputSystem()->GetKey(KeyCode::DownArrow))
		SetInput(InputState::Down_Arrow);
	else
		SetInput(InputState::Idle);
}

void PlayerInputComponent::SetInput(InputState state)
{
	if (_currentInputState != state)
	{
		_currentInputState = state;
		OnInputChanged(state);
	}
}