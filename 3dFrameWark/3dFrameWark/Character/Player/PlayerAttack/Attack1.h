#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

#include "../../../Actor/Actor.h"

class Attack1 :public Actor
{
public:

	Attack1(std::string l_name, const Vector3& l_position, float l_radius, const Matrix & matrix, float l_long = 0.0f, float l_width = 0.0f);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

private:
	float m_timer;
};


#endif