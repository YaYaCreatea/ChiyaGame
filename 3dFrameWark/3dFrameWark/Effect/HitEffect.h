#ifndef _HIT_EFFECT_H_
#define _HIT_EFFECT_H_

#include "../Actor/Actor.h"

class HitEffect :public Actor
{
public:

	HitEffect(const Vector3& l_position);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

private:
	float m_size;
	float m_timer;
};


#endif