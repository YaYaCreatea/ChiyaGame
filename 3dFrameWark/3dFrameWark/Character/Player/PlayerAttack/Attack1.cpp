#include "Attack1.h"

Attack1::Attack1(const Vector3 & l_position, float l_radius, const Matrix & matrix)
	:m_timer{ 2.0f }
{
	m_name = "Attack1";
	m_position = l_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{ 0.0f,3.0f,0.0f },l_radius };

	m_rotation.Forward(matrix.Forward());
}

void Attack1::update(float deltaTime)
{
	if (m_timer <= 0.0f)
		m_isdead = true;

	m_timer -= 1.0f*deltaTime;
}

void Attack1::draw() const
{
	//bodyCapsule_.draw(get_pose());
}

void Attack1::react(Actor & other)
{
	m_isdead = true;
}

