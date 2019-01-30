#include "Attack1.h"
#include "../../../Billboard/Billboard.h"

Attack1::Attack1(std::string l_name, const Vector3 & l_position, float l_radius, const Matrix & matrix, float l_long, float l_width)
	:m_timer{ 2.0f }
{
	m_name = l_name;
	m_position = l_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ -l_width / 2.0f,l_radius,0.0f },Vector3{ l_width / 2.0f,l_radius,l_long },l_radius };

	m_rotation.Forward(matrix.Forward());
	m_rotation.Left(matrix.Left());
}

void Attack1::update(float deltaTime)
{
	if (m_timer <= 0.0f)
		m_isdead = true;

	m_timer -= 1.0f*deltaTime;
}

void Attack1::draw() const
{
	//Billboard::bind(1);
	//Billboard::draw(m_position + Vector3{ 0.0f,5.0f,0.0f }, 50.0f, 0.5f, 0.5f,45.0f);
	bodyCapsule_.draw(get_pose());
}

void Attack1::react(Actor & other)
{
	m_isdead = true;
}

