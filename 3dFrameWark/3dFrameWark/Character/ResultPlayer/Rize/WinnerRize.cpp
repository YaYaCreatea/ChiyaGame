#include "WinnerRize.h"

#include "../../../World/IWorld.h"
#include "../../../StaticMesh/StaticMesh.h"

#include "../../Player/CharacterAnimationID.h"
#include "../../../assetsID/AssetsID.h"
#include "../../../Sound/Sound.h"

#include "../../../Camera/WinnerCamera/WinnerCamera.h"


WinnerRize::WinnerRize(
	IWorld & world,
	std::string l_name,
	const Vector3 & l_position, Matrix l_rotate,
	int l_model, int l_weapon)
	:mesh_{ l_model,0 },
	shape_{ l_model },
	m_motion{ (int)RizeAnmID::Winner },
	m_weapon{ l_weapon },
	m_pi{ l_position + Vector3::Zero },
	m_piVelo{ Vector3::Zero },
	m_timer{ 0.0f }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;

	world_->add_camera_rize(new_actor<WinnerCamera>(world, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, m_name));

	Sound::play_se((int)SoundID_SE::Rize_Win);
}

void WinnerRize::update(float deltaTime)
{
	oppai_yure(m_position, 10.0f, 0.75f, 30.0f);

	if (m_timer <= (mesh_.get_motion_end_time()*2.0f) - 2.0f)
	{
		mesh_.change_motion(m_motion);
		mesh_.update(deltaTime);
	}
	mesh_.transform(get_pose());
	mesh_.transform(get_pose(), 120, Vector3{ m_pi.x,m_pi.y,m_pi.z });
	mesh_.transform(get_pose(), 126, Vector3{ m_pi.x,m_pi.y,m_pi.z });
	shape_.update(m_timer, 100.0f);

	m_timer += deltaTime;
}

void WinnerRize::draw() const
{
	mesh_.draw();
	draw_weapon();
}

void WinnerRize::react(Actor & other)
{
}

void WinnerRize::handle_message(EventMessage message, void * param)
{
}

void WinnerRize::draw_weapon() const
{
	StaticMesh::bind(m_weapon);
	StaticMesh::transform(mesh_.get_bone_matrix(85));
	StaticMesh::draw();
}

void WinnerRize::oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass)
{
	const Vector3 stretch = m_pi - l_rest_position;
	const Vector3 force = -l_stiffness * stretch;
	const Vector3 acceleration = force / l_mass;
	m_piVelo = l_friction * (m_piVelo + acceleration);
	m_pi += m_piVelo;
}