#include "PlayerAction_Attack.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

#include "../PlayerAttack/Attack1.h"
#include "../PlayerAttack/AttackBullet.h"

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
				new_actor<Attack1>("Attack", l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
			);
			m_isSpawn = true;
		}

		else if (parameters_->Get_Name() == "Rize")
		{
			if (l_motion == (int)RizeAnmID::Combo1)
			{
				world_->add_actor(
					ActorGroup::RizeAction,
					new_actor<Attack1>("Attack", l_position + (l_pose.Forward()*18.0f), 5.0f, l_pose)
				);
				m_isSpawn = true;
			}
			else if (l_motion == (int)RizeAnmID::Combo2)
			{
				if (parameters_->Get_StateTimer() >= 30.0f)
				{
					world_->add_actor(
						ActorGroup::RizeAction,
						new_actor<Attack1>("Attack", l_position, 18.0f, l_pose)
					);
					m_isSpawn = true;
				}
			}
		}

		else if (parameters_->Get_Name() == "Syaro")
		{
			if (l_motion == (int)SyaroAnmID::Combo1)
			{
				world_->add_actor(
					ActorGroup::SyaroAction,
					new_actor<AttackBullet>("Attack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_pose)
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
			if (l_motion == (int)CocoaAnmID::Combo1)
			{
				world_->add_actor(
					ActorGroup::CocoaAction,
					new_actor<AttackBullet>("Attack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up*8.0f), 5.0f, l_pose)
				);
				m_isSpawn = true;
			}
			else if (l_motion == (int)CocoaAnmID::Combo2)
			{
				if (parameters_->Get_StateTimer() >= 20.0f)
				{
					world_->add_actor(
						ActorGroup::CocoaAction,
						new_actor<Attack1>("Attack", l_position + (l_pose.Forward()*10.0f) + (Vector3::Up*8.0f), 10.0f, l_pose)
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
