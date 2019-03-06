#ifndef _SPEAR_EFFECT2_H_
#define _SPEAR_EFFECT2_H_

#include "../Actor/Actor.h"
#include "EffectModel.h"

//槍攻撃エフェクト2
class SpearEffect2 :public Actor
{
public:

	SpearEffect2(const Vector3& l_position, const Matrix & matrix);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

private:
	EffectModel effect_;

	float m_alpha;
	float m_speed;

	Vector3 m_size;
};


#endif