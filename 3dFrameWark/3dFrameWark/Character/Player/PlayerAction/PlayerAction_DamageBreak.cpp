#include "PlayerAction_DamageBreak.h"

#include "../../../World/IWorld.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../PlayerParameters.h"

PlayerAction_DamageBreak::PlayerAction_DamageBreak(IWorld & world, PlayerParameters & parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_DamageBreak::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_friction = 2.0f;
}

void PlayerAction_DamageBreak::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	l_prevposition = l_position;
	l_position += (-l_pose.Forward()) * deltaTime;

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}
