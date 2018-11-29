#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../../Actor/Actor.h"
#include "../../AnimatedMesh/AnimatedMesh.h"

class Enemy :public Actor
{
public:
	//コンストラクタ
	Enemy(IWorld& world, const Vector3& l_position, int l_model);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:
	AnimatedMesh mesh_;		//アニメーションメッシュ
	int m_motion;			//モーション番号
	int m_weapon;			//武器モデル
	float m_state_timer;	//状態タイマー
};


#endif