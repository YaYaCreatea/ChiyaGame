#ifndef _BOSS0_H_
#define _BOSS0_H_

#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"

class Boss0 :public Actor
{
public:
	//コンストラクタ
	Boss0(IWorld& world, std::string l_name, const Vector3& l_position,int l_model);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:
	AnimatedMesh mesh_;

};

#endif