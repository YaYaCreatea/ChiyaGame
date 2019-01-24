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
	if (input_->Trigger(PAD_INPUT_3))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Combo1;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Combo1;
		m_nextActionID = PlayerStateName::Attack;
		m_nextAction = true;

		return;
	}

	if (input_->Trigger(PAD_INPUT_1))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::JumpReady;
		m_nextActionID = PlayerStateName::Jump;
		m_nextAction = true;

		return;
	}

	if (input_->Trigger(PAD_INPUT_6))
	{
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::DamageBreak;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::DamageBreak;
		m_nextActionID = PlayerStateName::Dash;
		m_nextAction = true;

		return;
	}


	if (parameters_->Get_Name() == "Chiya")
		l_motion = (int)ChiyaAnmID::Idle;
	else if (parameters_->Get_Name() == "Rize")
		l_motion = (int)RizeAnmID::Idle;

	//if (GamePad::state(GamePad::Up))
	//{
	//	m_nextAction = true;
	//}
	//else if (GamePad::state(GamePad::Down))
	//{
	//	m_nextAction = true;
	//}
	//if (GamePad::state(GamePad::Left))
	//{
	//	m_nextAction = true;
	//}
	//else if (GamePad::state(GamePad::Right))
	//{
	//	m_nextAction = true;
	//}

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
