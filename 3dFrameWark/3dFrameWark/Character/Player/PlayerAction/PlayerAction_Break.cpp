#include "PlayerAction_Break.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"

#include "../PlayerAttack/Attack1.h"

PlayerAction_Break::PlayerAction_Break(IWorld & world, PlayerParameters & parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_Break::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;
	m_isSpawn = false;
	m_isCombo = false;
}

void PlayerAction_Break::ActionUpdate(
	float deltaTime, 
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose,
	int & l_motion, Matrix & l_cameraRotation)
{
	l_prevposition = l_position;
	l_position += (l_pose.Forward() / 2.0f) * deltaTime;
	
	if (!m_isSpawn)
	{
		world_->add_actor(
			ActorGroup::PlayerAction,
			new_actor<Attack1>(l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
		);
		m_isSpawn = true;
	}

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}

