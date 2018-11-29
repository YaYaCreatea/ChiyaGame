#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../../Actor/Actor.h"
#include "../../AnimatedMesh/AnimatedMesh.h"

class Enemy :public Actor
{
public:
	//�R���X�g���N�^
	Enemy(IWorld& world, const Vector3& l_position, int l_model);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:
	AnimatedMesh mesh_;		//�A�j���[�V�������b�V��
	int m_motion;			//���[�V�����ԍ�
	int m_weapon;			//���탂�f��
	float m_state_timer;	//��ԃ^�C�}�[
};


#endif