#include "PlayerAction_Damage.h"

#include "../../../World/IWorld.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../PlayerParameters.h"

PlayerAction_Damage::PlayerAction_Damage(IWorld & world, PlayerParameters& parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_Damage::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_friction = 2.0f;
}

void PlayerAction_Damage::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	l_position += (-l_pose.Forward()/**m_friction*/) * deltaTime;
	//m_friction = MathHelper::Clamp(m_friction + 1.0f*deltaTime, 0.0f, 2.0f);

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}
