#include "KatanaEffect.h"

#include "../Billboard/Billboard.h"
#include "Effect.h"

KatanaEffect::KatanaEffect(const Vector3 & l_position, const Matrix & matrix, float l_pitch, float l_yaw)
	:effect_{ "asset/Effect/KatanaSlash.mv1" }
{
	m_position = l_position;
	m_alpha = 80.0f;
	m_rotation = matrix;

	m_pitch = l_pitch;
	m_yaw = l_yaw;

	effect_.transform(m_position, m_rotation, m_pitch, m_yaw);
}

void KatanaEffect::update(float deltaTime)
{
	if (m_alpha <= 0.0f)
		m_isdead = true;
	
	effect_.update(m_alpha);
	m_alpha -= deltaTime;
}

void KatanaEffect::draw() const
{
	effect_.draw();
}
