#include "PlayerAction_Dash.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"
#include "../../../Utility/MathHelper/MathHelper.h"

PlayerAction_Dash::PlayerAction_Dash(IWorld & world, PlayerParameters & parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
}

void PlayerAction_Dash::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_accel = 2.0f;
}

void PlayerAction_Dash::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	l_prevposition = l_position;
	l_velocity = l_pose.Forward()*m_accel;
	l_position += l_velocity * deltaTime;
	//m_accel = MathHelper::Clamp(m_accel - (deltaTime/25.0f), 0.0f, 2.0f);

	if (input_->Trigger(PAD_INPUT_3))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Combo1;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Combo1;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Combo1;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Combo1;
		m_nextActionID = PlayerStateName::Attack;
		m_nextAction = true;

		return;
	}

	else if (input_->Trigger(PAD_INPUT_1))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::JumpReady;
		m_nextActionID = PlayerStateName::Jump;
		m_nextAction = true;

		return;
	}

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}
