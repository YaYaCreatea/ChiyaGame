#ifndef _WINNER_CHIYA_H_
#define _WINNER_CHIYA_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"

class WinnerChiya :public Actor
{
public:
	//�R���X�g���N�^
	WinnerChiya(IWorld& world,
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

	//�����ς��h��
	void oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

private:

	//�A�j���[�V�������b�V��
	AnimatedMesh mesh_;

	//���[�V�����ԍ�
	int m_motion;
	//���탂�f��
	int m_weapon;

	//�J�����̉�]
	Matrix m_cameraRoate;

	//�����ς��ϐ�
	Vector3 m_pi;
	Vector3 m_piVelo;

	float m_timer;
};

#endif