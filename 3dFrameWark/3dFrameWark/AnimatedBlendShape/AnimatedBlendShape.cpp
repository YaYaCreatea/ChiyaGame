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

// 更新処理(状態)
void AnimatedBlendShape::update(PlayerStateName l_state)
{
	StateFaceUpdate(l_state);
}

// 更新処理(タイマー)
void AnimatedBlendShape::update(float l_timer, float l_cut0, float l_cut1)
{
	TimerFaceUpdate(l_timer, l_cut0, l_cut1);
}

// 状態ごとのブレンドシェイブの設定
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

// タイマーごとのブレンドシェイプの設定
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

// 攻撃、ダメージ時のブレンドシェイプの設定
void AnimatedBlendShape::Set_ShapeRate(float l_attackRate, float l_damageRate)
{
	m_shapeRateAttack = l_attackRate;
	m_shapeRateDamage = l_damageRate;
}

// 攻撃、ダメージ、笑顔時のブレンドシェイプの設定
void AnimatedBlendShape::Set_ShapeRate(float l_attackRate, float l_damageRate, float l_smileRate)
{
	m_shapeRateAttack = l_attackRate;
	m_shapeRateDamage = l_damageRate;
	m_shapeRateSmile = l_smileRate;
}

// ブレンドシェイプのアニメーション
void AnimatedBlendShape::FaceAnimation()
{
	SkeletalMesh::bind(m_model);
	SkeletalMesh::blendshape_animation(m_shapeRateAttack, m_shapeRateDamage, m_shapeRateSmile);
}