#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Actor/Actor.h"
#include "../../AnimatedMesh/AnimatedMesh.h"

#include "PlayerStateName.h"
#include "PlayerActionBase.h"
#include "PlayerActionBaseManager.h"
#include "PlayerActionPtr.h"

#include "PlayerParameters.h"

#include <map>

class TpsCamera;

class Player :public Actor
{
public:
	//�R���X�g���N�^
	Player(IWorld& world, std::string l_name, const Vector3& l_position, int l_model, int l_weapon);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:
	//��Ԃ̍X�V
	void update_state(float deltaTime);

	//��ԑJ��
	void change_state(PlayerStateName l_state, int l_motion);

	//�ړ�����
	void move(float deltaTime);

	//�U����
	void attack(float deltaTime);

	void attack2(float deltaTime);

	void attack3(float deltaTime);

	void attackMove(float deltaTime, const Vector3& l_movePoint);

	//�_���[�W��
	void damage(float deltaTime);

	//�W�����v��
	void jump(float deltaTime);

	//�ړ���
	void input_velocity(float l_forward_speed, float l_side_speed);

	//�U�����
	void face_to_orientation(float deltaTime, float l_forward_velo);

	//����̕`��
	void draw_weapon()const;

	void oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

private:
	using ActionMap = std::map<PlayerStateName, PlayerActionBaseManager>;
	ActionMap playerActions_;

	const float WALKSPEED{ 1.0f };
	const float GRAVITY{ -0.04f };

	AnimatedMesh mesh_;		//�A�j���[�V�������b�V��

	PlayerParameters parameters_;

	Matrix m_cameraRoate;
	float m_yaw;
	float m_yawroate;

	int m_jumpCount;

	Vector3 m_test;

	Vector3 m_pi;
	Vector3 m_piVelo;
	float m_testTime;
	bool isUp;

	bool m_isCombo;

	PlayerStateName m_state;//���

	int m_motion;			//���[�V�����ԍ�
	int m_weapon;			//���탂�f��

	float m_state_timer;	//��ԃ^�C�}�[

	float m_accel;

	float m_amausaGauge;
};

#endif