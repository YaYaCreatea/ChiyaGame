#include "PlayerAction_Jump.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"

PlayerAction_Jump::PlayerAction_Jump(IWorld & world, PlayerParameters& parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_Jump::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_jumpState = JumpState::Stand;
}

void PlayerAction_Jump::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	switch (m_jumpState)
	{
	case JumpState::Stand:
		if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
		{
			l_velocity.y = 1.0f;
			m_jumpState = JumpState::Jumping;
			l_motion = 10;
			parameters_->Set_StateTimer(0.0f);
		}
		break;

	case JumpState::Jumping:
		l_velocity.y += parameters_->Get_Gravity() * deltaTime;
		l_position += l_velocity * deltaTime;
		if (l_position.y < 0.0f)
		{
			l_position.y = 0.0f;
			m_jumpState = JumpState::Landing;
			l_motion = 11;
			parameters_->Set_StateTimer(0.0f);
		}
		break;

	case JumpState::Landing:
		if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
		{
			m_nextAction = true;
		}
		break;
	}
}