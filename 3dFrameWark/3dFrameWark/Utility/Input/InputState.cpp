#include "InputState.h"

#include <DxLib.h>

InputState::InputState()
{
}

InputState::~InputState()
{
}

void InputState::initialize(int l_inputType)
{
	m_inputType = l_inputType;
	m_currentState = 0;
	m_previousState = 0;
}

void InputState::update()
{
	m_previousState = m_currentState;
	m_currentState = GetJoypadInputState(m_inputType);
}

bool InputState::Stay(int button) const
{
	if ((m_currentState & button) != 0)
	{
		return true;
	}
	else if((m_currentState & button) == 0)
		return false;
}

bool InputState::Trigger(int button) const
{
	if ((m_currentState&~m_previousState&button) != 0)
	{
		return true;
	}
	else
		return false;
}

bool InputState::Release(int button) const
{
	if ((~m_currentState&m_previousState&button) != 0)
	{
		return true;
	}
	else
		return false;
}
