#include "PlayerAction_Attack.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"

#include "../PlayerAttack/Attack1.h"

PlayerAction_Attack::PlayerAction_Attack(IWorld & world, PlayerParameters& parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_Attack::ActionInitialize()
{
	m_nextAction = false;
	m_isSpawn = false;
	m_isCombo = false;
}

void PlayerAction_Attack::ActionUpdate(
	float deltaTime,
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose,
	int & l_motion, Matrix & l_cameraRotation)
{
	if (!m_isSpawn)
	{
		world_->add_actor(
			ActorGroup::PlayerAction,
			new_actor<Attack1>(l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
		);
		m_isSpawn = true;
	}

	if (GamePad::trigger(GamePad::X))
		m_isCombo = true;

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		if (m_isCombo)
		{			
			m_nextAction = true;
			m_nextActionID = (l_motion == 1) ? PlayerStateName::Attack : PlayerStateName::Break;
			l_motion = (l_motion == 1) ? 8 : 13;
		}
		else
		{
			m_nextAction = true;
			m_nextActionID = PlayerStateName::Idle;
		}
	}
}
