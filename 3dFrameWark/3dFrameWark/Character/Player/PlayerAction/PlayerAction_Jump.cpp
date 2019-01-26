#include "PlayerAction_Jump.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

PlayerAction_Jump::PlayerAction_Jump(IWorld & world, PlayerParameters& parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
}

void PlayerAction_Jump::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_jumpState = JumpState::Stand;
}

void PlayerAction_Jump::ActionUpdate(
	float deltaTime,
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, 
	Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	l_prevposition = l_position;

	switch (m_jumpState)
	{
	case JumpState::Stand:
		if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
		{
			l_velocity.y = 1.0f;
			m_jumpState = JumpState::Jumping;
			if (parameters_->Get_Name() == "Chiya")
				l_motion = (int)ChiyaAnmID::Jump;
			else if (parameters_->Get_Name() == "Rize")
				l_motion = (int)RizeAnmID::Jump;
			else if (parameters_->Get_Name() == "Syaro")
				l_motion = (int)SyaroAnmID::Jump;
			else if (parameters_->Get_Name() == "Cocoa")
				l_motion = (int)CocoaAnmID::Jump;
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
			if (parameters_->Get_Name() == "Chiya")
				l_motion = (int)ChiyaAnmID::Landing;
			else if (parameters_->Get_Name() == "Rize")
				l_motion = (int)RizeAnmID::Landing;
			else if (parameters_->Get_Name() == "Syaro")
				l_motion = (int)SyaroAnmID::Landing;
			else if (parameters_->Get_Name() == "Cocoa")
				l_motion = (int)CocoaAnmID::Landing;
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
