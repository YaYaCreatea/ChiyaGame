#include "SpearEffect.h"

#include "../Utility/MathHelper/MathHelper.h"
#include "Effect.h"
#include "../Sound/Sound.h"
#include "../assetsID/AssetsID.h"

/*
	リゼ用攻撃エフェクト
*/

SpearEffect::SpearEffect(const Vector3 & l_position, const Matrix & matrix)
	:effect_{ "asset/Effect/SpearEff.mv1" }
{
	m_position = l_position;
	m_rotation = matrix;
	m_alpha = 80.0f;
	m_speed = 1.0f;
	m_size = Vector3{ 0.3f,0.3f,0.3f };

	Sound::play_se((int)SoundID_SE::KatanaSlash);
}

void SpearEffect::update(float deltaTime)
{
	if (m_alpha <= 0.0f)
	{
		m_isdead = true;
		return;
	}

	// エフェクト更新
	effect_.update(m_alpha);
	effect_.transform(m_position, m_rotation, m_size);

	// パラメーター更新
	m_alpha -= m_speed * deltaTime;
	m_speed = MathHelper::Clamp(m_speed + (deltaTime / 10.0f), 1.0f, 5.0f);
	m_size = Vector3::Lerp(Vector3{ 0.3f,0.3f,0.3f }, Vector3{ 0.8f,0.8f,0.8f }, (80.0f - m_alpha) / 80.0f);
}

void SpearEffect::draw() const
{
	effect_.draw();
}
