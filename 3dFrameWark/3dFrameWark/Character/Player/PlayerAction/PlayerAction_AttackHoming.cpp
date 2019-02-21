#include "PlayerAction_AttackHoming.h"

#include "../../../World/IWorld.h"
#include "../../../Actor/Actor.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

PlayerAction_AttackHoming::PlayerAction_AttackHoming(IWorld & world, PlayerParameters & parameter, InputState & input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
}

void PlayerAction_AttackHoming::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Attack;

	m_distance = 0.0f;
	if (parameters_->Get_Name() == "Chiya")
		m_speed = 1.6f;
	else if (parameters_->Get_Name() == "Rize")
		m_speed = 1.4f;
}

void PlayerAction_AttackHoming::ActionUpdate(
	float deltaTime,
	Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose,
	int & l_motion, Matrix & l_cameraRotation)
{
	if (parameters_->Get_IsLockOn())
	{
		if (parameters_->Get_Name() == "Chiya")
		{
			if (parameters_->Get_DistanceNear() <= 12.0f
				|| parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				l_motion = (int)ChiyaAnmID::Combo1;
				m_nextAction = true;
			}
		}
		else if (parameters_->Get_Name() == "Rize")
		{
			if (parameters_->Get_DistanceNear() <= 18.0f
				|| parameters_->Get_StateTimer() >= (parameters_->Get_EndTime()*2.0f) - 2.0f)
			{
				l_motion = (int)RizeAnmID::Combo1;
				m_nextAction = true;
			}
		}

		l_prevposition = l_position;
		Vector3 l_directionOffset{ -parameters_->Get_LockOnDirection().x,0.0f,parameters_->Get_LockOnDirection().z };

		l_rotation = Matrix::CreateLookAt(l_position, l_position - l_directionOffset, l_pose.Up());
		l_position += (parameters_->Get_LockOnDirection()*m_speed) * deltaTime;
	}
	else
	{
		l_prevposition = l_position;
		l_position += (l_pose.Forward()*m_speed) * deltaTime;

		if (parameters_->Get_StateTimer() >= (parameters_->Get_EndTime() / 4.0f) - 2.0f)
		{
			if (parameters_->Get_Name() == "Chiya")
				l_motion = (int)ChiyaAnmID::Combo1;
			else if (parameters_->Get_Name() == "Rize")
				l_motion = (int)RizeAnmID::Combo1;
			m_nextAction = true;
		}
	}
}
