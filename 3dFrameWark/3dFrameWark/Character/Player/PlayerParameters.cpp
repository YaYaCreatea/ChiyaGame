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
	m_distanceNear = 0.0f;
	m_distanceToChiya = 0.0f;
	m_distanceToRize = 0.0f;
	m_distanceToSyaro = 0.0f;
	m_distanceToCocoa = 0.0f;
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
	m_Hp = MathHelper::ClampInt(m_Hp - l_damageHp, 0, m_HpMax);
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

void PlayerParameters::Set_DistanceNear(float l_distance)
{
	m_distanceNear = l_distance;
}

void PlayerParameters::Set_DistanceToChiya(float l_distance)
{
	m_distanceToChiya = l_distance;
}

void PlayerParameters::Set_DistanceToRize(float l_distance)
{
	m_distanceToRize = l_distance;
}

void PlayerParameters::Set_DistanceToSyaro(float l_distance)
{
	m_distanceToSyaro = l_distance;
}

void PlayerParameters::Set_DistanceToCocoa(float l_distance)
{
	m_distanceToCocoa = l_distance;
}

float PlayerParameters::Get_DistanceNear() const
{
	return m_distanceNear;
}

float PlayerParameters::Get_DistanceToChiya() const
{
	return m_distanceToChiya;
}

float PlayerParameters::Get_DistanceToRize() const
{
	return m_distanceToRize;
}

float PlayerParameters::Get_DistanceToSyaro() const
{
	return m_distanceToSyaro;
}

float PlayerParameters::Get_DistanceToCocoa() const
{
	return m_distanceToCocoa;
}

void PlayerParameters::DidDown()
{
	m_isDown = true;
}

bool PlayerParameters::Get_IsDown() const
{
	return m_isDown;
}
