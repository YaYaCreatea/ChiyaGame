#include "PlayerAction_Move.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"
#include "../../../Utility/Input/InputState.h"

PlayerAction_Move::PlayerAction_Move(IWorld& world, PlayerParameters& parameter, InputState& input)
{
	world_ = &world;
	parameters_ = &parameter;
	input_ = &input;
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
		//m_amausaGauge += 2.0f;
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::JumpReady;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::JumpReady;
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

	l_velocity = Vector3::Zero;
	float l_forward_speed{ 0.0f };
	float l_side_speed{ 0.0f };
	float l_forward_velo{ 0.0f };
	if (input_->Stay(PAD_INPUT_UP))
	{
		l_forward_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Move;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Move;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Move;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Move;
	}
	else if (input_->Stay(PAD_INPUT_DOWN))
	{
		l_forward_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Move;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Move;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Move;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Move;
	}
	if (input_->Stay(PAD_INPUT_LEFT))
	{
		l_side_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Move;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Move;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Move;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Move;
	}
	else if (input_->Stay(PAD_INPUT_RIGHT))
	{
		l_side_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
		if (parameters_->Get_Name() == "Chiya")
			l_motion = (int)ChiyaAnmID::Move;
		else if (parameters_->Get_Name() == "Rize")
			l_motion = (int)RizeAnmID::Move;
		else if (parameters_->Get_Name() == "Syaro")
			l_motion = (int)SyaroAnmID::Move;
		else if (parameters_->Get_Name() == "Cocoa")
			l_motion = (int)CocoaAnmID::Move;
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
