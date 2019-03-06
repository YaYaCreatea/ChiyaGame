#ifndef _ANIMATED_BLEND_SHAPE_H_
#define _ANIMATED_BLEND_SHAPE_H_

#include "../Character/Player/PlayerStateName.h"

//�u�����h�V�F�C�u�A�j���[�V����
class AnimatedBlendShape
{
public:
	//�R���X�g���N�^
	AnimatedBlendShape(int l_model);

	//�X�V(��Ԑݒ�)
	void update(PlayerStateName l_state);

	//�X�V(�^�C�}�[�ݒ�)
	void update(float l_timer, float l_cut0, float l_cut1 = 0.0f);

private:

	//��Ԃ��Ƃ̃V�F�C�v�X�V
	void StateFaceUpdate(PlayerStateName l_state);

	//�^�C�}�[�ł̃V�F�C�v�X�V
	void TimerFaceUpdate(float l_timer, float l_cut0, float l_cut1 = 0.0f);

	//�l�ݒ�(�U��,�_���[�W)
	void Set_ShapeRate(float l_attackRate, float l_damageRate);

	//�l�ݒ�(�U��,�_���[�W,����)
	void Set_ShapeRate(float l_attackRate, float l_damageRate,float l_smileRate);

	//�V�F�C�v�A�j���[�V����
	void FaceAnimation();

private:
	int m_model;
	float m_shapeRateAttack;
	float m_shapeRateDamage;
	float m_shapeRateSmile;
};

#endif