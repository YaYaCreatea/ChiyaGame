#include "PlayerAction_Idle.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

PlayerAction_Idle::PlayerAction_Idle(IWorld& world, PlayerParameters& parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
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
	l_velocity = Vector3{ 0.0f,l_velocity.y,0.0f };
	l_prevposition = l_position;

	if (input_->Trigger(PAD_INPUT_3))
	{
		//if (parameters_->Get_Name() == "Chiya")
		//	l_motion = (int)ChiyaAnmID::Combo1;
		if (parameters_->Get_Name() == "Chiya")
		{
			l_motion = (int)ChiyaAnmID::AttackHoming;
			m_nextActionID = PlayerStateName::AttackHoming;
		}
		else if (parameters_->Get_Name() == "Rize")
		{
			l_motion = (int)RizeAnmID::AttackHoming;
			m_nextActionID = PlayerStateName::AttackHoming;
		}
		else if (parameters_->Get_Name() == "Syaro")
		{
			l_motion = (int)SyaroAnmID::Combo1;
			m_nextActionID = PlayerStateName::Attack;
		}
		else if (parameters_->Get_Name() == "Cocoa")
		{
			l_motion = (int)CocoaAnmID::Combo1;
			m_nextActionID = PlayerStateName::Attack;
		}
		m_nextAction = true;

		return;
	}

	if (input_->Trigger(PAD_INPUT_1))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Jump;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Jump;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Jump;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Jump;
		m_nextActionID = PlayerStateName::Jump;
		m_nextAction = true;

		return;
	}

	if (input_->Trigger(PAD_INPUT_6))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Dash;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Dash;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Dash;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Dash;
		m_nextActionID = PlayerStateName::Dash;
		m_nextAction = true;

		return;
	}


	if (parameters_->Get_Name() == "Chiya")
		l_motion = (int)ChiyaAnmID::Idle;
	else if (parameters_->Get_Name() == "Rize")
		l_motion = (int)RizeAnmID::Idle;
	else if (parameters_->Get_Name() == "Syaro")
		l_motion = (int)SyaroAnmID::Idle;
	else if (parameters_->Get_Name() == "Cocoa")
		l_motion = (int)CocoaAnmID::Idle;

	if (input_->Stay(PAD_INPUT_UP))
	{
		m_nextAction = true;
	}
	else if (input_->Stay(PAD_INPUT_DOWN))
	{
		m_nextAction = true;
	}
	if (input_->Stay(PAD_INPUT_LEFT))
	{
		m_nextAction = true;
	}
	else if (input_->Stay(PAD_INPUT_RIGHT))
	{
		m_nextAction = true;
	}
}
