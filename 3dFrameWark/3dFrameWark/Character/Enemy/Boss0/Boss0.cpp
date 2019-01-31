#include "Boss0.h"

#include "../../../World/IWorld.h"

#include "../../../ActorGroupManager/ActorGroup.h"
#include "../../../EventMessage.h"

#include "BossBodyColl.h"


Boss0::Boss0(IWorld & world, std::string l_name, const Vector3 & l_position, int l_model)
	:mesh_{ l_model,0 }
{
	world_ = &world;
	m_name = l_name;
	m_position = l_position;
	m_prevposition = m_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,16.0f,0.0f },Vector3{0.0f,25.0f,0.0f},16.0f };

	world_->add_actor(
		ActorGroup::BossBody,
		new_actor<BossBodyColl>(l_position, get_pose())
	);
}

void Boss0::update(float deltaTime)
{
	m_rotation *= Matrix::CreateRotationY(deltaTime / 10.0f);
	mesh_.update(deltaTime);
	mesh_.transform(get_pose());
}

void Boss0::draw() const
{
	mesh_.draw();
	bodyCapsule_.draw(get_pose());
}

void Boss0::react(Actor & other)
{
}

void Boss0::handle_message(EventMessage message, void * param)
{
}
