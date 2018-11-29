#include "Enemy.h"

#include "../../World/IWorld.h"
#include "../../ActorGroupManager/ActorGroup.h"

Enemy::Enemy(IWorld & world, const Vector3 & l_position, int l_model)
	:mesh_{ l_model,0 },
	m_motion{ 0 },
	m_state_timer{ 0.0f }
{
	world_ = &world;
	m_name = "Enemy";
	m_position = l_position;
	m_prevposition = m_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{ 0.0f,20.0f,0.0f },3.0f };
}

void Enemy::update(float deltaTime)
{
	//モーション変更
	mesh_.change_motion(m_motion);

	//アニメーション更新
	mesh_.update(deltaTime);

	//行列の設定
	mesh_.transform(get_pose());

	auto l_player = world_->find_actor(ActorGroup::Player, "Player");
	if (l_player == nullptr)return;
	//Vector3 to_target = l_player->get_position() - m_position;
	//Matrix to_target_rotate = Matrix::CreateWorld(Vector3::Zero, to_target, m_rotation.Up());
	//m_rotation = Matrix::Lerp(m_rotation, to_target_rotate, 1.0f);

	m_position += m_velocity*deltaTime;
	m_velocity = Vector3::Zero;
}

void Enemy::draw() const
{
	mesh_.draw();
	bodyCapsule_.draw(get_pose());
}

void Enemy::react(Actor & other)
{
	if (other.get_name() == "Attack1")
		m_velocity = other.get_pose().Forward();
}

void Enemy::handle_message(EventMessage message, void * param)
{
}
