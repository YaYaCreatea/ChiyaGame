#include "AnimatedBlendShape.h"
#include "../SkeletalMesh/SkeletalMesh.h"
#include <DxLib.h>

AnimatedBlendShape::AnimatedBlendShape(int l_model)
{
	m_model = l_model;
	m_shapeRateAttack = 0.0f;
	m_shapeRateDamage = 0.0f;
}

void AnimatedBlendShape::update(PlayerStateName l_state)
{
	StateFaceUpdate(l_state);
}

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

void AnimatedBlendShape::Set_ShapeRate(float l_attackRate, float l_damageRate)
{	
	m_shapeRateAttack = l_attackRate;
	m_shapeRateDamage = l_damageRate;
}

void AnimatedBlendShape::FaceAnimation()
{
	SkeletalMesh::bind(m_model);
	SkeletalMesh::blendshape_animation(m_shapeRateAttack, m_shapeRateDamage);
}