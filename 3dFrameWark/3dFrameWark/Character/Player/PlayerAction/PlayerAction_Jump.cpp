#include "PlayerAction_Jump.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"
#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"

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
	// 振り向き移動制御
	Vector2 l_position2{ l_position.x,l_position.z };
	Vector2 l_prevposition2{ l_prevposition.x,l_prevposition.z };
	Vector2 l_direction2 = l_position2 - l_prevposition2;
	Vector2 l_direction2_inv = l_prevposition2 - l_position2;
	if (l_direction2_inv.LengthSquared() > 0.0f)
	{
		l_rotation = Matrix::Lerp(
			l_rotation,
			Matrix::CreateLookAt(
				l_position,
				l_position + Vector3{ -l_direction2_inv.x,0.0f,l_direction2_inv.y },
				l_pose.Up()),
			0.2f*deltaTime
		);
		l_prevposition = l_position;
	}

	l_prevposition = l_position;

	switch (m_jumpState)
	{
	// ジャンプ前
	case JumpState::Stand:
		Sound::play_se((int)SoundID_SE::Dash);
		l_velocity.y = 1.0f;
		m_jumpState = JumpState::Jumping;
		break;

	// ジャンプ中
	case JumpState::Jumping:
		l_velocity.y += parameters_->Get_Gravity() * deltaTime;

		l_position += l_velocity * deltaTime;
		if (l_position.y < 0.0f)
		{
			l_position.y = 0.0f;
			m_nextAction = true;
		}
		break;

	// 着地時
	case JumpState::Landing:
		if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
		{
			m_nextAction = true;
		}
		break;
	}
	
}
