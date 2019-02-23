#include "PlayerAction_Attack.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

#include "../../../Utility/Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"

#include "../PlayerAttack/Attack1.h"
#include "../PlayerAttack/AttackBullet.h"
#include "../../../Effect/KatanaEffect.h"

PlayerAction_Attack::PlayerAction_Attack(IWorld & world, PlayerParameters& parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
}

void PlayerAction_Attack::ActionInitialize()
{
	m_nextAction = false;
	m_isSpawn = false;
	m_isCombo = false;
	m_direction = Vector3::Zero;
}

void PlayerAction_Attack::ActionUpdate(
	float deltaTime,
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose,
	int & l_motion, Matrix & l_cameraRotation)
{
	if (!m_isSpawn)
	{
		if (parameters_->Get_Name() == "Chiya")
		{
			world_->add_actor(
				ActorGroup::ChiyaAction,
				new_actor<Attack1>("Attack", l_position + (l_pose.Forward()*6.0f), 8.0f, l_pose, 0.0f, 8.0f)
			);
			if (l_motion == (int)ChiyaAnmID::Combo1)
			{
				Sound::play_se((int)SoundID_SE::Chiya_Attack1);
				world_->add_actor(
					ActorGroup::Effect,
					new_actor<KatanaEffect>(l_position + l_pose.Up()*15.0f + (l_pose.Forward()*6.0f), l_pose, 180.0f, 180.0f)
				);
			}
			else if (l_motion == (int)ChiyaAnmID::Combo2)
			{
				Sound::play_se((int)SoundID_SE::Chiya_Attack2);
				world_->add_actor(
					ActorGroup::Effect,
					new_actor<KatanaEffect>(l_position + l_pose.Up()*15.0f + (l_pose.Forward()*6.0f), l_pose, -35.0f, 180.0f)
				);
			}
			m_isSpawn = true;
		}

		else if (parameters_->Get_Name() == "Rize")
		{
			if (l_motion == (int)RizeAnmID::Combo1)
			{
				Sound::play_se((int)SoundID_SE::Rize_Attack1);
				world_->add_actor(
					ActorGroup::RizeAction,
					new_actor<Attack1>("Attack", l_position + (l_pose.Forward()*18.0f), 5.0f, l_pose, 10.0f)
				);
				m_isSpawn = true;
			}
			else if (l_motion == (int)RizeAnmID::Combo2)
			{				
				if (parameters_->Get_StateTimer() >= 30.0f)
				{
					Sound::play_se((int)SoundID_SE::Rize_Attack2);
					world_->add_actor(
						ActorGroup::RizeAction,
						new_actor<Attack1>("Attack", l_position + Vector3{ 0.0f,-8.0f,0.0f }, 20.0f, l_pose)
					);
					m_isSpawn = true;
				}
			}
		}

		else if (parameters_->Get_Name() == "Syaro")
		{
			if (parameters_->Get_IsLockOn())
			{
				l_prevposition = l_position;
				Vector3 l_directionOffset{ -parameters_->Get_LockOnDirection().x,0.0f,parameters_->Get_LockOnDirection().z };
				l_rotation = Matrix::CreateLookAt(l_position, l_position - l_directionOffset, l_pose.Up());
			}

			if (l_motion == (int)SyaroAnmID::Combo1)
			{
				world_->add_actor(
					ActorGroup::SyaroAction,
					new_actor<AttackBullet>("Attack", l_position + (l_rotation.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_rotation)
				);
				m_isSpawn = true;
			}
			else if (l_motion == (int)SyaroAnmID::Combo2)
			{
				if (parameters_->Get_StateTimer() >= 20.0f)
				{
					world_->add_actor(
						ActorGroup::SyaroAction,
						new_actor<AttackBullet>("Attack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_pose)
					);
					m_isSpawn = true;
				}
			}
		}

		else if (parameters_->Get_Name() == "Cocoa")
		{
			if (parameters_->Get_IsLockOn())
			{
				l_prevposition = l_position;
				Vector3 l_directionOffset{ -parameters_->Get_LockOnDirection().x,0.0f,parameters_->Get_LockOnDirection().z };
				l_rotation = Matrix::CreateLookAt(l_position, l_position - l_directionOffset, l_pose.Up());
			}

			if (l_motion == (int)CocoaAnmID::Combo1)
			{
				world_->add_actor(
					ActorGroup::CocoaAction,
					new_actor<AttackBullet>("Attack", l_position + (l_rotation.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_rotation)
				);
				m_isSpawn = true;
			}
			else if (l_motion == (int)CocoaAnmID::Combo2)
			{
				if (parameters_->Get_StateTimer() >= 20.0f)
				{
					world_->add_actor(
						ActorGroup::CocoaAction,
						new_actor<Attack1>("Attack", l_position + (l_rotation.Forward()*10.0f) + (Vector3::Up*8.0f), 10.0f, l_rotation)
					);
					m_isSpawn = true;
				}
			}
		}
	}

	if (input_->Trigger(PAD_INPUT_3))
		m_isCombo = true;

	if (input_->Stay(PAD_INPUT_3)
		&& l_motion == (int)RizeAnmID::Combo2)
		m_isCombo = true;

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		if (m_isCombo)
		{
			if (parameters_->Get_Name() == "Chiya")
				m_nextActionID = (l_motion == (int)ChiyaAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Break;
			else if (parameters_->Get_Name() == "Rize")
				m_nextActionID = (l_motion == (int)RizeAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Break;
			else if (parameters_->Get_Name() == "Syaro")
				m_nextActionID = (l_motion == (int)SyaroAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Break;
			else if (parameters_->Get_Name() == "Cocoa")
				m_nextActionID = (l_motion == (int)CocoaAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Break;

			if (parameters_->Get_Name() == "Chiya")
				l_motion = (l_motion == (int)ChiyaAnmID::Combo1) ? (int)ChiyaAnmID::Combo2 : (int)ChiyaAnmID::Break;
			else if (parameters_->Get_Name() == "Rize")
				l_motion = (l_motion == (int)RizeAnmID::Combo1) ? (int)RizeAnmID::Combo2 : (int)RizeAnmID::BreakReady;
			else if (parameters_->Get_Name() == "Syaro")
				l_motion = (l_motion == (int)SyaroAnmID::Combo1) ? (int)SyaroAnmID::Combo2 : (int)SyaroAnmID::BreakReady;
			else if (parameters_->Get_Name() == "Cocoa")
				l_motion = (l_motion == (int)CocoaAnmID::Combo1) ? (int)CocoaAnmID::Combo2 : (int)CocoaAnmID::BreakReady;

			m_nextAction = true;
		}
		else
		{
			m_nextAction = true;
			m_nextActionID = PlayerStateName::Idle;
		}
	}
}
