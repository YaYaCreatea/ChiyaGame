#include "PlayerAction_Idle.h"

#include "../../../World/IWorld.h"

PlayerAction_Idle::PlayerAction_Idle(IWorld& world)
{
	world_ = &world;
}

void PlayerAction_Idle::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Move;
}

void PlayerAction_Idle::ActionUpdate(
	float deltaTime, 
	Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
	int& l_motion, Matrix& l_cameraRotation)
{
	if (GamePad::trigger(GamePad::X))
	{
		//m_amausaGauge += 2.0f;
		l_motion = 1;
		m_nextActionID = PlayerStateName::Attack;
		m_nextAction = true;
		
		return;
	}

	if (GamePad::trigger(GamePad::A))
	{
		//m_amausaGauge += 2.0f;
		l_motion = 9;
		m_nextActionID = PlayerStateName::Jump;
		m_nextAction = true;

		return;
	}

	if (GamePad::trigger(GamePad::B))
	{
		//m_amausaGauge += 2.0f;
		l_motion = 12;
		m_nextActionID = PlayerStateName::Damage;
		m_nextAction = true;

		return;
	}


	l_motion = 0;

	if (GamePad::state(GamePad::Up))
	{
		m_nextAction = true;
		
		//l_motion = 2;
	}
	else if (GamePad::state(GamePad::Down))
	{
		m_nextAction = true;
		//l_motion = 2;
	}
	if (GamePad::state(GamePad::Left))
	{
		m_nextAction = true;
		//l_motion = 2;
	}
	else if (GamePad::state(GamePad::Right))
	{
		m_nextAction = true;
		//l_motion = 2;
	}
}
