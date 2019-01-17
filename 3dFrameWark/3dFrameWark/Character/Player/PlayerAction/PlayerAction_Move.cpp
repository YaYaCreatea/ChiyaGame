#include "PlayerAction_Move.h"


PlayerAction_Move::PlayerAction_Move()
{
}

void PlayerAction_Move::ActionInitialize()
{
	m_nextAction = false;
}

void PlayerAction_Move::ActionUpdate(
	float deltaTime,
	Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
	int& l_motion, Matrix& l_cameraRotation)
{
	if (GamePad::trigger(GamePad::X))
	{
		//m_amausaGauge += 2.0f;
		l_motion = 1;
		m_nextActionID = PlayerStateName::Attack;
		m_nextAction = true;

		return;
	}

	if (GamePad::trigger(GamePad::A))
	{
		//m_amausaGauge += 2.0f;
		l_motion = 9;
		m_nextActionID = PlayerStateName::Jump;
		m_nextAction = true;

		return;
	}

	l_velocity = Vector3::Zero;
	float l_forward_speed{ 0.0f };
	float l_side_speed{ 0.0f };
	float l_forward_velo{ 0.0f };
	if (GamePad::state(GamePad::Up))
	{
		l_forward_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
		l_motion = 2;
	}
	else if (GamePad::state(GamePad::Down))
	{
		l_forward_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
		l_motion = 2;
	}
	if (GamePad::state(GamePad::Left))
	{
		l_side_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
		l_motion = 2;
	}
	else if (GamePad::state(GamePad::Right))
	{
		l_side_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
		l_motion = 2;
	}

	if (l_forward_speed == 0.0f&&l_side_speed == 0.0f)
	{
		m_nextActionID = PlayerStateName::Idle;
		m_nextAction = true;
		return;
	}

	face_to_orientation(deltaTime, l_position, l_prevposition, l_rotation, l_pose.Up());

	input_velocity(l_velocity, l_forward_speed, l_side_speed, l_cameraRotation);
	l_velocity.Normalize();
	l_position += l_velocity * deltaTime;	
}

void PlayerAction_Move::input_velocity(Vector3& l_velocity, float l_forward_speed, float l_side_speed, Matrix& l_cameraRotation)
{
	l_velocity +=
		((Vector3::Cross(l_cameraRotation.Right(), Vector3::Up)) *l_forward_speed)
		+ (Vector3::Cross(Vector3::Up, (Vector3::Cross(l_cameraRotation.Right(), Vector3::Up)))*l_side_speed);
}

void PlayerAction_Move::face_to_orientation(float deltaTime, Vector3& l_position, Vector3& l_prevposition, Matrix& l_rotation, Vector3 l_upAxis)
{
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
				l_upAxis),
			0.2f*deltaTime
		);
		//m_velocity += get_pose().Forward()*l_forward_velo;
		l_prevposition = l_position;
	}
}
