#include "FeadInOut.h"

#include <DxLib.h>

#include "../../Utility/MathHelper/MathHelper.h"

#include "../../assetsID/AssetsID.h"
#include "../../Graphics2D/Graphics2D.h"

// �t�F�[�h�p�����[�^������
void FeadInOut::Initialize(int l_startAlpha)
{
	m_alpha = l_startAlpha;
	m_isFead = true;
}

// �t�F�[�h�C������
void FeadInOut::FeadIn(float deltaTime)
{
	if (m_alpha >= 255)return;
	m_alpha = MathHelper::ClampInt(m_alpha + (int)(deltaTime*16.0f), 0, 255);
	m_isFead = (m_alpha >= 255) ? false : true;
}

// �t�F�[�h�A�E�g����
void FeadInOut::FeadOut(float deltaTime)
{
	if (m_alpha <= 0)return;
	m_alpha = MathHelper::ClampInt(m_alpha - (int)(deltaTime*16.0f), 0, 255);
	m_isFead = (m_alpha <= 0) ? false : true;
}

// �Ó]�摜�̕`��
void FeadInOut::DrawBack() const
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	Graphics2D::draw_sprite((int)SpriteID::BlackOutBack, Vector2::Zero);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �t�F�[�h���Ă��邩�ǂ���
bool FeadInOut::IsFead() const
{
	return m_isFead;
}
