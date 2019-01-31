#ifndef _BOSS_BODY_COLL_H_
#define _BOSS_BODY_COLL_H_

#include "../../../Actor/Actor.h"

class BossBodyColl :public Actor
{
public:

	BossBodyColl(const Vector3& l_position, const Matrix & matrix);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

};


#endif