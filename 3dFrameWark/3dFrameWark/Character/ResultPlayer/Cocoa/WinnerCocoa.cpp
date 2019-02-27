#include "WinnerCocoa.h"

#include "../../../World/IWorld.h"
#include "../../../StaticMesh/StaticMesh.h"

#include "../../Player/CharacterAnimationID.h"

#include "../../../Camera/WinnerCamera/WinnerCamera.h"

WinnerCocoa::WinnerCocoa(
	IWorld & world, 
	std::string l_name, const Vector3 & l_position, Matrix l_rotate, 
	int l_model)
	:mesh_{ l_model,0 },
	m_motion{ (int)CocoaAnmID::Break },
	m_timer{ 0.0f }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;

	world_->add_camera_cocoa(new_actor<WinnerCamera>(world, Vector3{ 0.0f,0.0f,0.0f }, 0.0f, m_name));

}

void WinnerCocoa::update(float deltaTime)
{
	if (m_timer <= (mesh_.get_motion_end_time()*2.0f) - 2.0f)
	{
		mesh_.change_motion(m_motion);
		mesh_.update(deltaTime);
	}
	mesh_.transform(get_pose());

	m_timer += deltaTime;
}

void WinnerCocoa::draw() const
{
	mesh_.draw();
}

void WinnerCocoa::react(Actor & other)
{
}

void WinnerCocoa::handle_message(EventMessage message, void * param)
{
}
