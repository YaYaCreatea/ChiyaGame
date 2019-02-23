#ifndef _KATANA_EFFECT_H_
#define _KATANA_EFFECT_H_

#include "../Actor/Actor.h"
#include "EffectModel.h"

class KatanaEffect :public Actor
{
public:

	KatanaEffect(const Vector3& l_position, const Matrix & matrix, float l_pitch = 0.0f, float l_yaw = 0.0f);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

private:
	EffectModel effect_;

	float m_alpha;
	float m_speed;
	float m_pitch;
	float m_yaw;
};


#endif