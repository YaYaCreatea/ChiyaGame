#include "PlayerParameters.h"

PlayerParameters::PlayerParameters()
{
}

void PlayerParameters::Initialize(std::string l_name)
{
	m_name = l_name;
	m_state_timer = 0.0f;
	m_end_time = 0.0f;
}

void PlayerParameters::Set_StateTimer(float l_state_timer)
{
	m_state_timer = l_state_timer;
}

void PlayerParameters::Add_StateTimer(float l_state_timer)
{
	m_state_timer += l_state_timer;
}

float PlayerParameters::Get_StateTimer() const
{
	return m_state_timer;
}

void PlayerParameters::Set_EndTime(float l_end_time)
{
	m_end_time = l_end_time;
}

float PlayerParameters::Get_EndTime() const
{
	return m_end_time;
}

float PlayerParameters::Get_Gravity() const
{
	return GRAVITY;
}

void PlayerParameters::Set_MyGroup(ActorGroup l_myGoup)
{
	m_myGroup = l_myGoup;
}

ActorGroup PlayerParameters::Get_MyGroup() const
{
	return m_myGroup;
}

std::string PlayerParameters::Get_Name() const
{
	return m_name;
}
