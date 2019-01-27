#include "AttackBullet.h"

#include "../../../CollisionMesh/CollisionMesh.h"
#include "../../../Billboard/Billboard.h"

AttackBullet::AttackBullet(std::string l_name, const Vector3 & l_position, float l_radius, const Matrix & matrix)
	:m_radius{ l_radius },
	m_timer{ 120.0f },
	m_bulletSpeed{ 2.5f },
	m_angle{ 0.0f }
{
	m_name = l_name;
	m_position = l_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,m_radius,0.0f },Vector3{ 0.0f,m_radius,0.0f },m_radius };

	m_rotation.Forward(matrix.Forward());
}

void AttackBullet::update(float deltaTime)
{
	m_position += (m_rotation.Forward()*m_bulletSpeed)*deltaTime;

	if (m_timer <= 0.0f || StageReact())
		m_isdead = true;
	m_timer -= 1.0f*deltaTime;

	m_angle += 0.1f*deltaTime;
}

void AttackBullet::draw() const
{
	Billboard::bind(0);
	Billboard::draw(m_position + Vector3{ 0.0f,m_radius,0.0f }, m_radius*2.0f, 0.5f, 0.5f, m_angle);

	//“–‚½‚è”»’è
	//bodyCapsule_.draw(get_pose());
}

void AttackBullet::react(Actor & other)
{
	m_isdead = true;
}

bool AttackBullet::StageReact()
{
	return CollisionMesh::collide_capsule(
		m_position + Vector3{ 0.0f,m_radius,0.0f },
		m_position + Vector3{ 0.0f,m_radius,0.0f },
		m_radius,
		&m_position);
}
