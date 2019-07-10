#include "HandEffect.h"

#include "../Utility/MathHelper/MathHelper.h"
#include "Effect.h"
#include "../Sound/Sound.h"
#include "../assetsID/AssetsID.h"

/*
	�R�R�A�U���G�t�F�N�g
*/

HandEffect::HandEffect(const Vector3 & l_position, const Matrix & matrix)
	:effect_{ "asset/Effect/HandEff.mv1" }
{
	m_position = l_position;
	m_rotation = matrix;
	m_alpha = 80.0f;
	m_speed = 1.0f;
	m_size = Vector3{ 0.5f,0.5f,0.5f };

	Sound::play_se((int)SoundID_SE::KatanaSlash);
}

void HandEffect::update(float deltaTime)
{
	if (m_alpha <= 0.0f)
	{
		m_isdead = true;
		return;
	}

	// �G�t�F�N�g�̍X�V
	effect_.update(m_alpha);
	effect_.transform(m_position, m_rotation, m_size);

	// �p�����[�^�[�X�V
	m_alpha -= m_speed * deltaTime;
	m_speed = MathHelper::Clamp(m_speed + (deltaTime / 10.0f), 1.0f, 5.0f);
	m_size = Vector3::Lerp(Vector3{ 0.5f,0.5f,0.5f }, Vector3{ 1.5f,1.5f,1.5f }, (80.0f - m_alpha) / 80.0f);
}

void HandEffect::draw() const
{
	effect_.draw();
}
