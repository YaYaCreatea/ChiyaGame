#include "Attack1.h"

Attack1::Attack1(std::string l_name, const Vector3 & l_position, float l_radius, const Matrix & matrix, float l_long, float l_width)
	:m_timer{ 2.0f }
{
	m_name = l_name;
	m_position = l_position;

	// 当たり判定の生成
	bodyCapsule_ = BoundingCapsule{ Vector3{ -l_width / 2.0f,l_radius,0.0f },Vector3{ l_width / 2.0f,l_radius,l_long },l_radius };

	// 回転設定
	m_rotation.Forward(matrix.Forward());
	m_rotation.Left(matrix.Left());
}

void Attack1::update(float deltaTime)
{
	// 消滅チェック
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

