#include "WinnerSyaro.h"

#include "../../../World/IWorld.h"
#include "../../../StaticMesh/StaticMesh.h"

#include "../../Player/CharacterAnimationID.h"

#include "../../../Camera/WinnerCamera/WinnerCamera.h"

WinnerSyaro::WinnerSyaro(
	IWorld & world,
	std::string l_name, const Vector3 & l_position, Matrix l_rotate,
	int l_model, int l_weapon)
	:mesh_{ l_model,0 },
	m_motion{ (int)SyaroAnmID::Combo1 },
	m_weapon{ l_weapon },
	m_timer{ 0.0f }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;

	world_->add_camera_syaro(new_actor<WinnerCamera>(world, Vector3{ 0.0f,0.0f,0.0f }, 0.0f, m_name));
}

void WinnerSyaro::update(float deltaTime)
{
	if (m_timer <= (mesh_.get_motion_end_time()*2.0f) - 2.0f)
	{
		mesh_.change_motion(m_motion);
		mesh_.update(deltaTime);
	}
	mesh_.transform(get_pose());

	m_timer += deltaTime;
}

void WinnerSyaro::draw() const
{
	mesh_.draw();
	draw_weapon();
}

void WinnerSyaro::react(Actor & other)
{
}

void WinnerSyaro::handle_message(EventMessage message, void * param)
{
}

void WinnerSyaro::draw_weapon() const
{
	StaticMesh::bind(m_weapon);
	StaticMesh::transform(mesh_.get_bone_matrix(77));
	StaticMesh::draw();
}
