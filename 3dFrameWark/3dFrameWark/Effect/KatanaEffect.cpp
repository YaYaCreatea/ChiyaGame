#include "KatanaEffect.h"

#include "../Utility/MathHelper/MathHelper.h"
#include "Effect.h"
#include "../Sound/Sound.h"
#include "../assetsID/AssetsID.h"

/*
	千夜用攻撃エフェクト
*/

KatanaEffect::KatanaEffect(const Vector3 & l_position, const Matrix & matrix, float l_pitch, float l_yaw)
	:effect_{ "asset/Effect/KatanaSlash.mv1" }
{
	m_position = l_position;
	m_alpha = 80.0f;
	m_speed = 1.0f;
	m_rotation = matrix;

	m_pitch = l_pitch;
	m_yaw = l_yaw;

	effect_.transform(m_position, m_rotation, m_pitch, m_yaw);

	Sound::play_se((int)SoundID_SE::KatanaSlash);
}

void KatanaEffect::update(float deltaTime)
{
	if (m_alpha <= 0.0f)
		m_isdead = true;

	// エフェクト更新
	effect_.update(m_alpha);

	// パラメーター更新
	m_alpha -= m_speed * deltaTime;
	m_speed = MathHelper::Clamp(m_speed + (deltaTime / 10.0f), 1.0f, 5.0f);
}

void KatanaEffect::draw() const
{
	effect_.draw();
}
