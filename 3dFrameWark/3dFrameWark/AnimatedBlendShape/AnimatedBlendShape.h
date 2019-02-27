#ifndef _ANIMATED_BLEND_SHAPE_H_
#define _ANIMATED_BLEND_SHAPE_H_

#include "../Character/Player/PlayerStateName.h"

class AnimatedBlendShape
{
public:
	AnimatedBlendShape(int l_model);
	void update(PlayerStateName l_state);

private:

	void StateFaceUpdate(PlayerStateName l_state);

	void Set_ShapeRate(float l_attackRate, float l_damageRate);

	void FaceAnimation();

private:
	int m_model;
	float m_shapeRateAttack;
	float m_shapeRateDamage;
};

#endif