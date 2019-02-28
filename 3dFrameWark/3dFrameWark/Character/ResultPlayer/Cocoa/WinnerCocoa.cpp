#include "WinnerCocoa.h"

#include "../../../World/IWorld.h"
#include "../../../StaticMesh/StaticMesh.h"

#include "../../Player/CharacterAnimationID.h"
#include "../../../assetsID/AssetsID.h"
#include "../../../Sound/Sound.h"

#include "../../../Camera/WinnerCamera/WinnerCamera.h"

WinnerCocoa::WinnerCocoa(
	IWorld & world,
	std::string l_name, const Vector3 & l_position, Matrix l_rotate,
	int l_model)
	:mesh_{ l_model,0 },
	shape_{ l_model },
	m_motion{ (int)CocoaAnmID::Break },
	m_timer{ 0.0f }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;

	world_->add_camera_cocoa(new_actor<WinnerCamera>(world, Vector3{ 0.0f,0.0f,0.0f }, 0.0f, m_name));

	Sound::play_se((int)SoundID_SE::Cocoa_Win);
}

void WinnerCocoa::update(float deltaTime)
{
	if (m_timer <= (mesh_.get_motion_end_time()*2.0f) - 2.0f)
	{
		mesh_.change_motion(m_motion);
		mesh_.update(deltaTime);
	}
	mesh_.transform(get_pose());
	shape_.update(m_timer, 0.0f);

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
