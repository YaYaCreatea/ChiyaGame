#include "BossBodyColl.h"

BossBodyColl::BossBodyColl(const Vector3 & l_position, const Matrix & matrix)
{
	m_position = l_position;
	m_rotation = matrix;
	m_prevposition = m_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,25.0f,-25.0f },Vector3{0.0f,25.0f,20.0f},16.0f };
}

void BossBodyColl::update(float deltaTime)
{
	m_rotation *= Matrix::CreateRotationY(deltaTime / 10.0f);
}

void BossBodyColl::draw() const
{
	bodyCapsule_.draw(get_pose());
}

void BossBodyColl::react(Actor & other)
{
}
