#ifndef _ANIMATED_BLEND_SHAPE_H_
#define _ANIMATED_BLEND_SHAPE_H_

#include "../Character/Player/PlayerStateName.h"

class AnimatedBlendShape
{
public:
	AnimatedBlendShape(int l_model);
	void update(PlayerStateName l_state);
	void update(float l_timer, float l_cut0, float l_cut1 = 0.0f);

private:

	void StateFaceUpdate(PlayerStateName l_state);

	void TimerFaceUpdate(float l_timer, float l_cut0, float l_cut1 = 0.0f);

	void Set_ShapeRate(float l_attackRate, float l_damageRate);

	void Set_ShapeRate(float l_attackRate, float l_damageRate,float l_smileRate);

	void FaceAnimation();

private:
	int m_model;
	float m_shapeRateAttack;
	float m_shapeRateDamage;
	float m_shapeRateSmile;
};

#endif