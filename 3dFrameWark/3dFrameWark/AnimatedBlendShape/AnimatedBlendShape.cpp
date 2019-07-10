#include "AnimatedBlendShape.h"
#include "../SkeletalMesh/SkeletalMesh.h"
#include <DxLib.h>

AnimatedBlendShape::AnimatedBlendShape(int l_model)
{
	m_model = l_model;
	m_shapeRateAttack = 0.0f;
	m_shapeRateDamage = 0.0f;
	m_shapeRateSmile = 0.0f;
}

// �X�V����(���)
void AnimatedBlendShape::update(PlayerStateName l_state)
{
	StateFaceUpdate(l_state);
}

// �X�V����(�^�C�}�[)
void AnimatedBlendShape::update(float l_timer, float l_cut0, float l_cut1)
{
	TimerFaceUpdate(l_timer, l_cut0, l_cut1);
}

// ��Ԃ��Ƃ̃u�����h�V�F�C�u�̐ݒ�
void AnimatedBlendShape::StateFaceUpdate(PlayerStateName l_state)
{
	switch (l_state)
	{
	case PlayerStateName::Idle:
		Set_ShapeRate(0.0f, 0.0f);
		break;
	case PlayerStateName::Attack:
		Set_ShapeRate(1.0f, 0.0f);
		break;
	case PlayerStateName::Damage:
		Set_ShapeRate(0.0f, 1.0f);
		break;
	}

	FaceAnimation();
}

// �^�C�}�[���Ƃ̃u�����h�V�F�C�v�̐ݒ�
void AnimatedBlendShape::TimerFaceUpdate(float l_timer, float l_cut0, float l_cut1)
{
	if (l_timer <= l_cut0)
	{
		Set_ShapeRate(1.0f, 0.0f, 0.0f);
	}
	else if (l_timer > l_cut0)
	{
		Set_ShapeRate(0.0f, 0.0f, 1.0f);
	}

	FaceAnimation();
}

// �U���A�_���[�W���̃u�����h�V�F�C�v�̐ݒ�
void AnimatedBlendShape::Set_ShapeRate(float l_attackRate, float l_damageRate)
{
	m_shapeRateAttack = l_attackRate;
	m_shapeRateDamage = l_damageRate;
}

// �U���A�_���[�W�A�Ί玞�̃u�����h�V�F�C�v�̐ݒ�
void AnimatedBlendShape::Set_ShapeRate(float l_attackRate, float l_damageRate, float l_smileRate)
{
	m_shapeRateAttack = l_attackRate;
	m_shapeRateDamage = l_damageRate;
	m_shapeRateSmile = l_smileRate;
}

// �u�����h�V�F�C�v�̃A�j���[�V����
void AnimatedBlendShape::FaceAnimation()
{
	SkeletalMesh::bind(m_model);
	SkeletalMesh::blendshape_animation(m_shapeRateAttack, m_shapeRateDamage, m_shapeRateSmile);
}