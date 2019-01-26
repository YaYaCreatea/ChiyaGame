#ifndef _ATTACK_BULLET_H_
#define _ATTACK_BULLET_H_

#include "../../../Actor/Actor.h"

class AttackBullet :public Actor
{
public:

	AttackBullet(std::string l_name, const Vector3& l_position, float l_radius, const Matrix & matrix);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

private:
	float m_radius;
	float m_timer;
	float m_bulletSpeed;
	
};


#endif