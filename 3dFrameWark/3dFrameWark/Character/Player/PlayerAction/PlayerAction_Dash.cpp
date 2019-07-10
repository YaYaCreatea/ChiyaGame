#include "PlayerAction_Dash.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"


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

	Sound::play_se((int)SoundID_SE::Dash);
}

void PlayerAction_Dash::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	// ˆÚ“®§Œä
	l_prevposition = l_position;
	l_velocity = l_pose.Forward()*m_accel;
	l_position += l_velocity * deltaTime;

	// UŒ‚”h¶
	if (input_->Trigger(PAD_INPUT_3))
	{
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

	// ƒWƒƒƒ“ƒv”h¶
	else if (input_->Trigger(PAD_INPUT_1))
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

	// ƒ_ƒbƒVƒ…”h¶
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

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}
