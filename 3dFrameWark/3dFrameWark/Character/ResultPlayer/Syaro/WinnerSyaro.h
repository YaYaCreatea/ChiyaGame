#ifndef _WINNER_SYARO_H_
#define _WINNER_SYARO_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../AnimatedBlendShape/AnimatedBlendShape.h"

class WinnerSyaro :public Actor
{
public:
	//�R���X�g���N�^
	WinnerSyaro(IWorld& world,
		std::string l_name, const Vector3& l_position, Matrix l_rotate,
		int l_model, int l_weapon
	);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:

	//����̕`��
	void draw_weapon()const;

private:

	//�A�j���[�V�������b�V��
	AnimatedMesh mesh_;
	AnimatedBlendShape shape_;

	//���[�V�����ԍ�
	int m_motion;
	//���탂�f��
	int m_weapon;

	//�J�����̉�]
	Matrix m_cameraRoate;

	float m_timer;
};

#endif