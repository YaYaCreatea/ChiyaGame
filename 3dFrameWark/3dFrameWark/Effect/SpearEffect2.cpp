#include "SpearEffect2.h"

#include "../Utility/MathHelper/MathHelper.h"
#include "Effect.h"
#include "../Sound/Sound.h"
#include "../assetsID/AssetsID.h"

/*
	リゼ用ブレイク攻撃用エフェクト
*/

SpearEffect2::SpearEffect2(const Vector3 & l_position, const Matrix & matrix)
	:effect_{ "asset/Effect/SpearEff2.mv1" }
{
	m_position = l_position;
	m_rotation = matrix;
	m_alpha = 80.0f;
	m_speed = 1.0f;
	m_size = Vector3{ 1.0f,1.0f,1.0f };

	Sound::play_se((int)SoundID_SE::KatanaSlash);
}

void SpearEffect2::update(float deltaTime)
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
	m_size = Vector3::Lerp(Vector3{ 1.0f,1.0f,1.0f }, Vector3{ 3.0f,3.0f,3.0f }, (80.0f - m_alpha) / 80.0f);
}

void SpearEffect2::draw() const
{
	effect_.draw();
}
