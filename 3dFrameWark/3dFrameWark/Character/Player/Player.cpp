#include "Player.h"

#include "../../World/IWorld.h"
#include "../../ActorGroupManager/ActorGroup.h"

#include "../../Utility/Input/GamePad/GamePad.h"
#include "../../StaticMesh/StaticMesh.h"
#include "../../SkeletalMesh/SkeletalMesh.h"
#include "../../Utility/MathHelper/MathHelper.h"
#include "../../Utility/Quaternion/Quaternion.h"
#include "../../EventMessage.h"

#include "../../Utility/Vector2/Vector2.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "PlayerAttack\Attack1.h"


Player::Player(IWorld& world, const Vector3& l_position, int l_model, int l_weapon)
	:mesh_{ l_model,0 },
	m_state{ PlayerStateName::Move },
	m_motion{ 0 },
	m_weapon{ l_weapon },
	m_state_timer{ 0.0f },
	m_yaw{ 0.0f },
	m_yawroate{ 0.0f },
	m_jumpCount{ 2 },
	m_accel{ 1.0f },
	m_amausaGauge{ 0.0f },
	m_pi{ Vector3::Zero },
	m_testTime{ 0.0f },
	isUp{ false }
{
	world_ = &world;
	m_name = "Player";
	m_position = l_position;
	m_prevposition = m_position;

	//body_ = BoundingSphere{ Vector3{0.0f,3.0f,0.0f},3.0f };
	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{0.0f,20.0f,0.0f},3.0f };
}

void Player::update(float deltaTime)
{
	update_state(deltaTime);
	m_position.x = MathHelper::Clamp(m_position.x, -75.0f, 75.0f);
	m_position.z = MathHelper::Clamp(m_position.z, -151.0f, 156.0f);

	//���[�V�����ύX
	mesh_.change_motion(m_motion);

	//�A�j���[�V�����X�V
	mesh_.update(deltaTime);

	//�s��̐ݒ�
	if (!isUp)
	{
		if (m_testTime >= 1.0f)isUp = true;
		m_testTime += (deltaTime / 50.0f);
	}
	else
	{
		if (m_testTime <= 0.0f)isUp = false;
		m_testTime -= (deltaTime / 50.0f);
	}
	m_pi = Vector3::Lerp(Vector3{ 0.0f,-0.2f,0.0f }, Vector3{ 0.0f,0.2f,0.0f }, m_testTime / 1.0f);


	mesh_.transform(get_pose());
	mesh_.transform(get_pose(), 151, m_pi);
	mesh_.transform(get_pose(), 157, m_pi);
}

void Player::draw() const
{
	mesh_.draw();
	//bodyCapsule_.draw(get_pose());
	DrawFormatStringF(0.0f, 0.0f, 1, "(%f,%f,%f)", m_position.x, m_position.y, m_position.z);
	DrawFormatStringF(0.0f, 20.0f, 1, "(%d)", (int)m_state);
	DrawFormatStringF(100.0f, 20.0f, 1, "(%f)", m_state_timer);
	DrawFormatStringF(0.0f, 40.0f, 1, "(%f)", m_amausaGauge);
	DrawFormatStringF(0.0f, 60.0f, 1, "(%f)", m_testTime);
	draw_weapon();
}

void Player::handle_message(EventMessage message, void * param)
{
	switch (message)
	{
	case EventMessage::CameraMatrix:
		m_cameraRoate = *(Matrix*)param;
		break;
	}
}

void Player::react(Actor& other)
{
	m_test = get_bodyCapsule().PushedBack_CapsuleCapsule(other.get_bodyCapsule());
	m_position = Vector3(m_prevposition.x, m_position.y, m_prevposition.z);

	//change_state(PlayerStateName::Damage, MotionDamage);
}

void Player::update_state(float deltaTime)
{
	switch (m_state)
	{
	case PlayerStateName::Move:
		move(deltaTime);
		break;
	case PlayerStateName::Attack:
		attack(deltaTime);
		break;
	case PlayerStateName::Attack2:
		attack2(deltaTime);
		break;
	case PlayerStateName::Attack3:
		attack2(deltaTime);
		break;
	case PlayerStateName::Damage:
		damage(deltaTime);
		break;
	case PlayerStateName::Jump:
		jump(deltaTime);
		break;
	};

	m_state_timer += 1.0f*deltaTime;
}

void Player::change_state(PlayerStateName l_state, int l_motion)
{
	m_state_timer = 0.0f;
	m_motion = l_motion;
	m_state = l_state;
}

void Player::move(float deltaTime)
{
	if (GamePad::trigger(GamePad::X) && m_state != PlayerStateName::Attack)
	{
		m_amausaGauge += 2.0f;
		world_->add_actor(ActorGroup::PlayerAction, new_actor<Attack1>(m_position + (get_pose().Forward()*10.0f), 10.0f, get_pose()));
		change_state(PlayerStateName::Attack, 1);
		return;
	}

	if (GamePad::trigger(GamePad::A))
	{
		m_velocity.y = 1.0f;
		m_jumpCount--;
		change_state(PlayerStateName::Jump, 3);
		return;
	}

	/*if (GamePad::state(GamePad::B))
	{
		m_velocity += get_pose().Forward()*(WALKSPEED*2.0f)*deltaTime;
		m_position += m_velocity;
		change_state(PlayerStateName::Move, 2);
		return;
	}*/

	int l_motion{ 0 };

	m_velocity = Vector3::Zero;
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

	change_state(PlayerStateName::Move, l_motion);
	face_to_orientation(deltaTime, l_forward_velo);

	input_velocity(l_forward_speed, l_side_speed);
	m_velocity.Normalize();
	m_position += m_velocity * deltaTime;
}

void Player::attack(float deltaTime)
{
	attackMove(deltaTime, Vector3::Zero);
	if (m_state_timer < mesh_.get_motion_end_time() && GamePad::trigger(GamePad::X))
	{
		m_amausaGauge += 2.0f;
		m_accel = 1.0f;
		world_->add_actor(ActorGroup::PlayerAction,
			new_actor<Attack1>(m_position + (get_pose().Forward()*10.0f), 10.0f, get_pose()));
		change_state(PlayerStateName::Attack2, 4);
		return;
	}
	else if (m_state_timer >= mesh_.get_motion_end_time() *2.0f)
	{
		m_accel = 1.0f;
		move(deltaTime);
	}
}

void Player::attack2(float deltaTime)
{
	attackMove(deltaTime, Vector3::Zero);
	if (m_state_timer < mesh_.get_motion_end_time() && GamePad::trigger(GamePad::X))
	{
		m_amausaGauge += 2.0f;
		m_accel = 1.0f;
		world_->add_actor(ActorGroup::PlayerAction,
			new_actor<Attack1>(m_position + (get_pose().Forward()*10.0f), 10.0f, get_pose()));
		change_state(PlayerStateName::Attack2, 1);
		return;
	}
	else if (m_state_timer >= mesh_.get_motion_end_time())
	{
		m_accel = 1.0f;
		move(deltaTime);
	}
}

void Player::attack3(float deltaTime)
{
	attackMove(deltaTime, Vector3::Zero);
	if (m_state_timer >= mesh_.get_motion_end_time() *2.0f)
	{
		m_accel = 1.0f;
		move(deltaTime);
	}
}

void Player::attackMove(float deltaTime, const Vector3 & l_movePoint)
{
	m_prevposition = m_position;
	m_position += (get_pose().Forward())*m_accel * deltaTime;

	m_accel = MathHelper::Clamp(m_accel -= 0.1f*deltaTime, 0.0f, 1.0f);
}

void Player::damage(float deltaTime)
{
	if (m_state_timer >= mesh_.get_motion_end_time())
		move(deltaTime);
}

void Player::jump(float deltaTime)
{
	if (GamePad::trigger(GamePad::A) && m_jumpCount > 0)
	{
		m_velocity.y = 1.0f;
		m_jumpCount--;
	}

	float l_forward_speed{ 0.0f };
	float l_side_speed{ 0.0f };
	float l_forward_velo{ 0.0f };
	if (GamePad::state(GamePad::Up))
	{
		l_forward_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
	}
	else if (GamePad::state(GamePad::Down))
	{
		l_forward_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
	}
	if (GamePad::state(GamePad::Left))
	{
		l_side_speed = -WALKSPEED;
		l_forward_velo = WALKSPEED;
	}
	else if (GamePad::state(GamePad::Right))
	{
		l_side_speed = WALKSPEED;
		l_forward_velo = WALKSPEED;
	}

	face_to_orientation(deltaTime, 0.1f);
	input_velocity(l_forward_speed, l_side_speed);
	m_velocity.y += GRAVITY * deltaTime;

	Vector2 l_velocity2{ m_velocity.x,m_velocity.z };
	l_velocity2.Normalize();

	Vector3 l_velocity3{ l_velocity2.x,m_velocity.y,l_velocity2.y };
	m_position += l_velocity3 * deltaTime;

	if (m_position.y < 0.0f)
	{
		m_position.y = 0.0f;
		m_jumpCount = 2;
		move(deltaTime);
	}
}

void Player::input_velocity(float l_forward_speed, float l_side_speed)
{
	m_velocity +=
		((Vector3::Cross(m_cameraRoate.Right(), Vector3::Up)) *l_forward_speed)
		+ (Vector3::Cross(Vector3::Up, (Vector3::Cross(m_cameraRoate.Right(), Vector3::Up)))*l_side_speed);
}

void Player::face_to_orientation(float deltaTime, float l_forward_velo)
{
	Vector2 l_position2{ m_position.x,m_position.z };
	Vector2 l_prevposition2{ m_prevposition.x,m_prevposition.z };

	Vector2 l_direction2 = l_position2 - l_prevposition2;
	Vector2 l_direction2_inv = l_prevposition2 - l_position2;

	if (l_direction2_inv.LengthSquared() > 0.0f)
	{
		m_rotation = Matrix::Lerp(
			m_rotation,
			Matrix::CreateLookAt(
				m_position,
				m_position + Vector3{ -l_direction2_inv.x,0.0f,l_direction2_inv.y },
				get_pose().Up()),
			0.3f*deltaTime
		);
		//m_velocity += get_pose().Forward()*l_forward_velo;
		m_prevposition = m_position;
	}

	//Vector3 l_direction = m_position - m_prevposition;
	//Vector3 l_direction_inv = m_prevposition - m_position;
	//if (l_direction_inv.LengthSquared() > 0.0f)
	//{
	//	m_rotation = Matrix::Lerp(
	//		m_rotation,
	//		Matrix::CreateLookAt(m_position, m_position + Vector3{ -l_direction_inv.x,0.0f,l_direction_inv.z }, get_pose().Up()),
	//		0.3f*deltaTime
	//		);
	//	//m_velocity += get_pose().Forward()*l_forward_velo;
	//	m_prevposition = m_position;
	//}
}

void Player::draw_weapon()const
{
	StaticMesh::bind(m_weapon);
	StaticMesh::transform(mesh_.get_bone_matrix(116));
	StaticMesh::draw();
}
