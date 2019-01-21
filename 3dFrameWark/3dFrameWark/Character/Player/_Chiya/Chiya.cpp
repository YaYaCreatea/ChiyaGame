#include "Chiya.h"

#include "../../../World/IWorld.h"
#include "../../../ActorGroupManager/ActorGroup.h"

#include "../../../Utility/Input/GamePad/GamePad.h"
#include "../../../StaticMesh/StaticMesh.h"
#include "../../../SkeletalMesh/SkeletalMesh.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../../../Utility/Quaternion/Quaternion.h"
#include "../../../EventMessage.h"

#include "../../../CollisionMesh/CollisionMesh.h"

#include "../PlayerAction/PlayerAction_Idle.h"
#include "../PlayerAction/PlayerAction_Move.h"
#include "../PlayerAction/PlayerAction_Attack.h"
#include "../PlayerAction/PlayerAction_Break.h"
#include "../PlayerAction/PlayerAction_Jump.h"
#include "../PlayerAction/PlayerAction_Damage.h"

#include "../CharacterAnimationID.h"

Chiya::Chiya(IWorld & world, std::string l_name, const Vector3 & l_position, int l_model, int l_weapon)
	:mesh_{ l_model,0 },
	input_{},
	m_state{ PlayerStateName::Idle },
	m_motion{ 0 },
	m_weapon{ l_weapon },
	m_pi{ Vector3::Zero },
	m_piVelo{ Vector3::Zero }
{
	world_ = &world;
	m_name = l_name;
	m_position = l_position;
	m_prevposition = m_position;

	parameters_.Initialize(m_name);

	input_.initialize(DX_INPUT_KEY_PAD1);

	playerActions_[PlayerStateName::Idle].add(new_action<PlayerAction_Idle>(world, parameters_,input_));
	playerActions_[PlayerStateName::Move].add(new_action<PlayerAction_Move>(world, parameters_, input_));
	playerActions_[PlayerStateName::Attack].add(new_action<PlayerAction_Attack>(world, parameters_, input_));
	playerActions_[PlayerStateName::Break].add(new_action<PlayerAction_Break>(world, parameters_));
	playerActions_[PlayerStateName::Jump].add(new_action<PlayerAction_Jump>(world, parameters_));
	playerActions_[PlayerStateName::Damage].add(new_action<PlayerAction_Damage>(world, parameters_));
	playerActions_[m_state].initialize();

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{0.0f,20.0f,0.0f},3.0f };
}

void Chiya::update(float deltaTime)
{
	input_.update();

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

	//���[�V�����ύX
	mesh_.change_motion(m_motion);

	parameters_.Set_EndTime(mesh_.get_motion_end_time());

	//�A�j���[�V�����X�V
	mesh_.update(deltaTime);

	mesh_.transform(get_pose());
	mesh_.transform(get_pose(), 151, m_pi);
	mesh_.transform(get_pose(), 157, m_pi);

	CollisionMesh::collide_sphere(m_position + Vector3{ 0.0f,3.0f,0.0f }, m_position + Vector3{ 0.0f,20.0f,0.0f }, 3.0f, &m_position);

	auto l_camera0 = world_->get_camera0();
	if (l_camera0 == nullptr)return;
	m_cameraRoate = l_camera0->get_pose();
}

void Chiya::draw() const
{
	mesh_.draw();
	draw_weapon();
}

void Chiya::react(Actor & other)
{
	if (other.get_name() == "Attack1"
		&& m_state != PlayerStateName::Damage)
	{
		m_motion = (int)ChiyaAnmID::Damage;
		m_state = PlayerStateName::Damage;
		playerActions_[m_state].initialize();
		parameters_.Set_StateTimer(0.0f);
		return;
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
	const Vector3 acceleration = (force / l_mass)*2.0f;
	m_piVelo = l_friction * (m_piVelo + acceleration);
	m_pi += m_piVelo;
}