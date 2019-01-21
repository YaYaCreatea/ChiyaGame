#include "PlayerAction_Attack.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

#include "../PlayerAttack/Attack1.h"

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
			world_->add_actor(
				ActorGroup::PlayerAction,
				new_actor<Attack1>(l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
			);
		else if (parameters_->Get_Name() == "Rize")
			world_->add_actor(
				ActorGroup::EnemyAction,
				new_actor<Attack1>(l_position + (l_pose.Forward()*10.0f), 10.0f, l_pose)
			);
		m_isSpawn = true;
	}

	if (input_->Trigger(PAD_INPUT_3))
		m_isCombo = true;

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		if (m_isCombo)
		{			
			if (parameters_->Get_Name() == "Chiya")
				m_nextActionID = (l_motion == (int)ChiyaAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Break;
			else if (parameters_->Get_Name() == "Rize")
				m_nextActionID = (l_motion == (int)RizeAnmID::Combo1) ? PlayerStateName::Attack : PlayerStateName::Attack;

			if (parameters_->Get_Name() == "Chiya")
				l_motion = (l_motion == (int)ChiyaAnmID::Combo1) ? (int)ChiyaAnmID::Combo2 : (int)ChiyaAnmID::Break;
			else if (parameters_->Get_Name() == "Rize")
				l_motion = (l_motion == (int)RizeAnmID::Combo1) ? (int)RizeAnmID::Combo2 : (int)RizeAnmID::Combo1;
				
			m_nextAction = true;
		}
		else
		{
			m_nextAction = true;
			m_nextActionID = PlayerStateName::Idle;
		}
	}
	
}
