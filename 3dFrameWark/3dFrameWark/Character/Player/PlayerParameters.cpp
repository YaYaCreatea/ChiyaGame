#include "PlayerParameters.h"

#include "../../Utility/MathHelper/MathHelper.h"

PlayerParameters::PlayerParameters()
{
}

void PlayerParameters::Initialize(std::string l_name, int l_Hp)
{
	m_name = l_name;
	m_Hp = l_Hp;
	m_HpMax = l_Hp;
	m_state_timer = 0.0f;
	m_end_time = 0.0f;
	m_breakDirection = Vector3::Zero;
	m_lockOnDirection = Vector3::Zero;
	m_distance = 0.0f;
	m_isLockOn = true;
	m_isDown = false;
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

void PlayerParameters::Damage_HP(int l_damageHp)
{
	m_Hp = MathHelper::Clamp(m_Hp - l_damageHp, 0, m_HpMax);
}

int PlayerParameters::Get_HP() const
{
	return m_Hp;
}

int PlayerParameters::Get_MaxHP() const
{
	return m_HpMax;
}

void PlayerParameters::Set_BreakDirection(Vector3 l_direction)
{
	m_breakDirection = l_direction;
}

Vector3 PlayerParameters::Get_BreakDirection() const
{
	return m_breakDirection;
}

void PlayerParameters::Set_LockOnDirection(Vector3 l_direction)
{
	m_lockOnDirection = l_direction;
}

void PlayerParameters::LockOnDirectionNormlize()
{
	m_lockOnDirection.Normalize();
}

Vector3 PlayerParameters::Get_LockOnDirection() const
{
	return m_lockOnDirection;
}

void PlayerParameters::LockOn(bool l_isLockOn)
{
	m_isLockOn = l_isLockOn;
}

bool PlayerParameters::Get_IsLockOn() const
{
	return m_isLockOn;
}

void PlayerParameters::DidDown()
{
	m_isDown = true;
}

bool PlayerParameters::Get_IsDown() const
{
	return m_isDown;
}
