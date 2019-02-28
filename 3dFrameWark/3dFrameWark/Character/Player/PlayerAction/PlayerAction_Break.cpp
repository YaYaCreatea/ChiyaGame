#include "PlayerAction_Break.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"

#include "../../../Utility/Input/InputState.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include"../../../Utility/Quaternion/Quaternion.h"

#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"

#include "../PlayerAttack/Attack1.h"
#include "../PlayerAttack/AttackBullet.h"
#include "../../../Effect/KatanaEffect.h"

PlayerAction_Break::PlayerAction_Break(IWorld & world, PlayerParameters & parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
}

void PlayerAction_Break::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_breakState = BreakState::Ready;
	m_isSpawn = false;
	m_charge = 0.0f;
	m_yawRotation = 0.0f;
}

void PlayerAction_Break::ActionUpdate(
	float deltaTime,
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose,
	int & l_motion, Matrix & l_cameraRotation)
{
	if (parameters_->Get_Name() == "Chiya")
	{
		l_prevposition = l_position;
		l_position += (l_pose.Forward() / 2.0f) * deltaTime;

		if (!m_isSpawn&&parameters_->Get_StateTimer() >= 25.0f)
		{
			Sound::play_se((int)SoundID_SE::Chiya_Attack1);
			world_->add_actor(
				ActorGroup::ChiyaAction,
				new_actor<Attack1>("BreakAttack", l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
			);
			world_->add_actor(
				ActorGroup::Effect,
				new_actor<KatanaEffect>(l_position + l_pose.Up()*15.0f + (l_pose.Forward()*14.0f), l_pose, 110.0f, 180.0f)
			);
			m_isSpawn = true;
		}

		if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 4.0f)
		{
			m_nextAction = true;
		}
	}

	else if (parameters_->Get_Name() == "Rize")
	{

		switch (m_breakState)
		{
		case BreakState::Ready:
			if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				m_breakState = BreakState::Charge;
				l_motion = (int)RizeAnmID::BreakCharge;
				parameters_->Set_StateTimer(0.0f);
			}
			break;
		case BreakState::Charge:
			if (input_->Stay(PAD_INPUT_3))
			{
				m_charge = MathHelper::Clamp((parameters_->Get_StateTimer() + 2.0f) / 60.0f, 0.0f, 2.0f);
				if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
				{
					m_breakState = BreakState::ChargeMax;
					l_motion = (int)RizeAnmID::BreakChargeMax;
					parameters_->Set_StateTimer(0.0f);
				}
			}
			else if (input_->Release(PAD_INPUT_3))
			{
				Sound::play_se((int)SoundID_SE::Rize_Attack3);
				m_breakState = BreakState::Break;
				l_motion = (int)RizeAnmID::Break;
				parameters_->Set_StateTimer(0.0f);
			}
			break;

		case BreakState::ChargeMax:
			m_charge = 2.0f;
			if (input_->Release(PAD_INPUT_3))
			{
				Sound::play_se((int)SoundID_SE::Rize_Attack4);
				m_breakState = BreakState::Break;
				l_motion = (int)RizeAnmID::Break;
				parameters_->Set_StateTimer(0.0f);
			}
			break;

		case BreakState::Break:

			if (((int)parameters_->Get_StateTimer() % 6) == 0)
			{
				world_->add_actor(
					ActorGroup::RizeAction,
					new_actor<Attack1>("BreakAttack", l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
				);
			}

			l_prevposition = l_position;
			l_position += (l_pose.Forward()*m_charge) * deltaTime;

			if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
			{
				m_nextAction = true;
			}
			break;
		}

	}

	else if (parameters_->Get_Name() == "Syaro")
	{
		switch (m_breakState)
		{
		case BreakState::Ready:
			if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				Sound::play_se((int)SoundID_SE::Syaro_Attack2);
				m_breakState = BreakState::Break;
				l_motion = (int)SyaroAnmID::Break;
				parameters_->Set_StateTimer(0.0f);
			}
			break;

		case BreakState::Break:

			m_yawRotation = 0.0f;
			if (input_->Stay(PAD_INPUT_LEFT))
				m_yawRotation = -0.2f;
			else if (input_->Stay(PAD_INPUT_RIGHT))
				m_yawRotation = 0.2f;

			l_rotation *= Matrix::CreateRotationY(m_yawRotation);
			l_prevposition = l_position;

			if (((int)parameters_->Get_StateTimer() % 10) == 0)
			{
				world_->add_actor(
					ActorGroup::SyaroAction,
					new_actor<AttackBullet>("BreakAttack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_pose)
				);
			}

			if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
			{
				m_nextAction = true;
			}
			break;
		}

	}

	else if (parameters_->Get_Name() == "Cocoa")
	{
		switch (m_breakState)
		{
		case BreakState::Ready:

			l_velocity = Vector3{ 0.0f,0.2f,0.0f };

			m_yawRotation = 0.0f;
			if (input_->Stay(PAD_INPUT_LEFT))
				m_yawRotation = -1.0f;
			else if (input_->Stay(PAD_INPUT_RIGHT))
				m_yawRotation = 1.0f;
			l_rotation *= Matrix::CreateRotationY(m_yawRotation);
			l_position += l_velocity * deltaTime;
			l_prevposition = l_position;

			if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				Sound::play_se((int)SoundID_SE::Cocoa_Attack1);
				m_breakState = BreakState::Break;
				l_motion = (int)CocoaAnmID::Break;
				parameters_->Set_StateTimer(0.0f);
			}
			break;

		case BreakState::Break:

			if (!m_isSpawn&&parameters_->Get_StateTimer() >= 10.0f)
			{
				world_->add_actor(
					ActorGroup::CocoaAction,
					new_actor<AttackBullet>("BreakAttack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up), 15.0f, l_pose)
				);
				m_isSpawn = true;
			}

			if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				m_breakState = BreakState::End;
				l_motion = (int)CocoaAnmID::BreakEnd;
				parameters_->Set_StateTimer(0.0f);
			}
			break;

		case BreakState::End:
			if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				m_nextAction = true;
			}
			break;
		}
	}
}

