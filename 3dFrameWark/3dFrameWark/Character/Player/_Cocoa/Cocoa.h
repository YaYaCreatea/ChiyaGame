#ifndef _COCOA_H_
#define _COCOA_H_

#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../Utility/Input/InputState.h"

#include "../PlayerStateName.h"
#include "../PlayerActionBase.h"
#include "../PlayerActionBaseManager.h"
#include "../PlayerActionPtr.h"

#include "../PlayerParameters.h"

#include <map>

class Cocoa :public Actor
{
public:
	//�R���X�g���N�^
	Cocoa(IWorld& world, std::string l_name, const Vector3& l_position, int l_model);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:

	//�����ς��h��
	void oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

private:

	//�A�N�V�����Ǘ�
	using ActionMap = std::map<PlayerStateName, PlayerActionBaseManager>;
	ActionMap playerActions_;

	//�A�j���[�V�������b�V��
	AnimatedMesh mesh_;

	InputState input_;

	//�v���C���[�̃p�����[�^��
	PlayerParameters parameters_;

	//�v���C���[���
	PlayerStateName m_state;

	//���[�V�����ԍ�
	int m_motion;
	//���탂�f��
	int m_weapon;

	//�J�����̉�]
	Matrix m_cameraRoate;

	//�����ς��ϐ�
	Vector3 m_pi;
	Vector3 m_piVelo;
};

#endif