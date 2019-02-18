#include "Chiya.h"

#include "../../../World/IWorld.h"
#include "../../../ActorGroupManager/ActorGroup.h"

#include "../../../Utility/Input/GamePad/GamePad.h"
#include "../../../StaticMesh/StaticMesh.h"
#include "../../../SkeletalMesh/SkeletalMesh.h"

#include "../../../Graphics2D/Graphics2D.h"
#include "../../../Graphics3D/Graphics3D.h"
#include "../../../Billboard/Billboard.h"
#include "../../../Effect/Effect.h"

#include "../../../Utility/MathHelper/MathHelper.h"
#include "../../../Utility/Quaternion/Quaternion.h"
#include "../../../EventMessage.h"

#include "../../../CollisionMesh/CollisionMesh.h"

#include "../../../Camera/DuelCamera/DuelCamera.h"
#include "../PlayerAction/PlayerAction_Idle.h"
#include "../PlayerAction/PlayerAction_Move.h"
#include "../PlayerAction/PlayerAction_Attack.h"
#include "../PlayerAction/PlayerAction_Break.h"
#include "../PlayerAction/PlayerAction_Jump.h"
#include "../PlayerAction/PlayerAction_Damage.h"
#include "../PlayerAction/PlayerAction_DamageBreak.h"
#include "../PlayerAction/PlayerAction_Down.h"
#include "../PlayerAction/PlayerAction_DownIdle.h"
#include "../PlayerAction/PlayerAction_Dash.h"
#include "../PlayerAction/PlayerAction_AttackHoming.h"

#include "../CharacterAnimationID.h"
#include "../../../assetsID/AssetsID.h"

#include <EffekseerForDXLib.h>

Chiya::Chiya(IWorld & world, std::string l_name, const Vector3 & l_position, Matrix l_rotate, int l_model, int l_weapon, int l_numPlayer)
	:mesh_{ l_model,0 },
	input_{},
	m_state{ PlayerStateName::Idle },
	m_motion{ 0 },
	m_weapon{ l_weapon },
	m_pi{ l_position + Vector3::Zero },
	m_piVelo{ Vector3::Zero },
	m_forward{ Vector3::Zero },
	m_distance{ 0.0f }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;
	m_numPlayer = l_numPlayer;

	parameters_.Initialize(m_name, 51);

	if (m_numPlayer == 1)
	{
		world_->add_camera_chiya(new_actor<DuelCamera>(world, Vector3{ 0.0f,25.0f,35.0f }, 180.0f, m_name, m_numPlayer));
		input_.initialize(DX_INPUT_PAD1);
	}
	else if (m_numPlayer == 2)
	{
		world_->add_camera_chiya(new_actor<DuelCamera>(world, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, m_name, m_numPlayer));
		input_.initialize(DX_INPUT_PAD2);
	}

	playerActions_[PlayerStateName::Idle].add(new_action<PlayerAction_Idle>(world, parameters_, input_));
	playerActions_[PlayerStateName::Move].add(new_action<PlayerAction_Move>(world, parameters_, input_));
	playerActions_[PlayerStateName::Attack].add(new_action<PlayerAction_Attack>(world, parameters_, input_));
	playerActions_[PlayerStateName::Break].add(new_action<PlayerAction_Break>(world, parameters_, input_));
	playerActions_[PlayerStateName::Jump].add(new_action<PlayerAction_Jump>(world, parameters_, input_));
	playerActions_[PlayerStateName::Damage].add(new_action<PlayerAction_Damage>(world, parameters_));
	playerActions_[PlayerStateName::DamageBreak].add(new_action<PlayerAction_DamageBreak>(world, parameters_));
	playerActions_[PlayerStateName::Down].add(new_action<PlayerAction_Down>(world, parameters_));
	playerActions_[PlayerStateName::DownIdle].add(new_action<PlayerAction_DownIdle>(world, parameters_));
	playerActions_[PlayerStateName::Dash].add(new_action<PlayerAction_Dash>(world, parameters_, input_));
	playerActions_[PlayerStateName::AttackHoming].add(new_action<PlayerAction_AttackHoming>(world, parameters_, input_));
	playerActions_[m_state].initialize();

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{0.0f,20.0f,0.0f},3.0f };
}

void Chiya::update(float deltaTime)
{
	input_.update();

	if (m_position.y > 0.0f&&m_state != PlayerStateName::Jump)
	{
		m_velocity.y += parameters_.Get_Gravity() * deltaTime;
		m_position += m_velocity * deltaTime;
	}

	lockOnCheck();

	playerActions_[m_state].update(
		deltaTime, m_position, m_velocity, m_prevposition, m_rotation, get_pose(),
		m_motion, m_cameraRoate);

	oppai_yure(m_position, 10.0f, 0.75f, 30.0f);

	parameters_.Add_StateTimer(1.0f*deltaTime);

	if (playerActions_[m_state].Get_NextActionFlag())
	{
		playerActions_[m_state].NextAction(m_state, parameters_);
		playerActions_[m_state].initialize();
	}

	//モーション変更
	mesh_.change_motion(m_motion);

	parameters_.Set_EndTime(mesh_.get_motion_end_time());

	//アニメーション更新
	mesh_.update(deltaTime);

	mesh_.transform(get_pose());
	mesh_.transform(get_pose(), 151, Vector3{ m_pi.x,m_pi.y,m_pi.z });
	mesh_.transform(get_pose(), 157, Vector3{ m_pi.x,m_pi.y,m_pi.z });

	set_IsDown(parameters_.Get_IsDown());

	CollisionMesh::collide_capsule(
		m_position + Vector3{ 0.0f,3.0f,0.0f },
		m_position + Vector3{ 0.0f,20.0f,0.0f },
		3.0f, &m_position);

	auto l_camera0 = world_->get_camera_chiya();
	if (l_camera0 == nullptr)return;
	m_cameraRoate = l_camera0->get_pose();
}

void Chiya::draw() const
{
	mesh_.draw();
	draw_weapon();

	if (!parameters_.Get_IsLockOn())
	{
		if (m_numPlayer == 1)
			Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff, Vector2::Zero);
		else if (m_numPlayer == 2)
			Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff, Vector2{ 640.0f,0.0f });
	}
	else
	{
		if (m_numPlayer == 1)
			Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn, Vector2::Zero);
		else if (m_numPlayer == 2)
			Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn, Vector2{ 640.0f,0.0f });
	}


	if (m_numPlayer == 1)
		Graphics2D::draw_sprite_RCS(
		(int)SpriteID::HpGauge,
			Vector2{ 50.0f,30.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });
	else if (m_numPlayer == 2)
		Graphics2D::draw_sprite_RCS(
		(int)SpriteID::HpGauge,
			Vector2{ 690.0f,30.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });


	/*DrawFormatStringF(
		20.0f, 40.0f, 1, "(%f)",
		Vector3::Dot(m_forward, m_direction));
	DrawFormatStringF(
		20.0f, 70.0f, 1, "(%d)",
		parameters_.Get_IsLockOn());*/
	DrawFormatStringF(
		20.0f, 100.0f, 1, "(%d)",
		input_.Get_Type());
}

void Chiya::react(Actor & other)
{
	if (parameters_.Get_HP() > 0)
	{
		if (other.get_name() == "Attack")
		{
			input_.Vibration(500, 200);
			//StartJoypadVibration(DX_INPUT_PAD1, 250, 200);

			m_motion = (int)ChiyaAnmID::Damage;
			m_state = PlayerStateName::Damage;
			playerActions_[m_state].initialize();
			parameters_.Set_StateTimer(0.0f);
			mesh_.change_motion_same(m_motion);
			parameters_.Damage_HP(1);

			if (parameters_.Get_HP() <= 0)
			{
				m_motion = (int)ChiyaAnmID::Down;
				m_state = PlayerStateName::Down;
				playerActions_[m_state].initialize();
				parameters_.Set_StateTimer(0.0f);
				return;
			}

			return;
		}

		else if (other.get_name() == "BreakAttack")
		{
			input_.Vibration(600, 200);
			//StartJoypadVibration(DX_INPUT_PAD1, 600, 200);

			m_motion = (int)ChiyaAnmID::DamageBreak;
			m_state = PlayerStateName::DamageBreak;
			playerActions_[m_state].initialize();
			parameters_.Set_BreakDirection(other.get_pose().Forward());
			parameters_.Set_StateTimer(0.0f);
			parameters_.Damage_HP(2);

			if (parameters_.Get_HP() <= 0)
			{
				m_motion = (int)ChiyaAnmID::Down;
				m_state = PlayerStateName::Down;
				playerActions_[m_state].initialize();
				parameters_.Set_StateTimer(0.0f);
				return;
			}

			return;
		}
	}

	m_position = Vector3(m_prevposition.x, m_position.y, m_prevposition.z);
}

void Chiya::handle_message(EventMessage message, void * param)
{
}

void Chiya::draw_weapon() const
{
	StaticMesh::bind(m_weapon);
	StaticMesh::transform(mesh_.get_bone_matrix(116));
	StaticMesh::draw();
}

void Chiya::oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass)
{
	const Vector3 stretch = m_pi - l_rest_position;
	const Vector3 force = -l_stiffness * stretch;
	const Vector3 acceleration = force / l_mass;
	m_piVelo = l_friction * (m_piVelo + acceleration);
	m_pi += m_piVelo;
}

void Chiya::lockOnCheck()
{
	auto l_rize = world_->find_actor(ActorGroup::Rize, "Rize");
	auto l_syaro = world_->find_actor(ActorGroup::Syaro, "Syaro");
	auto l_cocoa = world_->find_actor(ActorGroup::Cocoa, "Cocoa");
	if (l_rize != nullptr)
	{
		parameters_.Set_LockOnDirection(l_rize->get_position() - m_position);
		m_distance = Vector3::Distance(m_position, l_rize->get_position());
	}
	if (l_syaro != nullptr)
	{
		parameters_.Set_LockOnDirection(l_syaro->get_position() - m_position);
		m_distance = Vector3::Distance(m_position, l_syaro->get_position());
	}
	if (l_cocoa != nullptr)
	{
		parameters_.Set_LockOnDirection(l_cocoa->get_position() - m_position);
		m_distance = Vector3::Distance(m_position, l_cocoa->get_position());
	}
	parameters_.LockOnDirectionNormlize();
	m_forward = m_cameraRoate.Forward();
	m_forward.Normalize();
	

	if (m_distance > 100.0f
		|| Vector3::Dot(m_forward, parameters_.Get_LockOnDirection()) < (0.9f - ((100.0f - m_distance) / 500.0f)))
	{
		parameters_.LockOn(false);
		return;
	}

	else if (Vector3::Dot(m_forward, parameters_.Get_LockOnDirection()) >= (0.9f - ((100.0f - m_distance) / 500.0f)))
	{
		parameters_.LockOn(true);
	}
}
