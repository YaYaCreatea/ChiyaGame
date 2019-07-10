#include "PlayerActionBaseManager.h"

#include "PlayerParameters.h"

// �A�N�V�����̒ǉ�
void PlayerActionBaseManager::add(const PlayerActionPtr & action)
{
	action_ = action;
}

// �o�^�A�N�V�����̏�����
void PlayerActionBaseManager::initialize()
{
	action_->ActionInitialize();
}

// �o�^�A�N�V�����̍X�V����
void PlayerActionBaseManager::update(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion, Matrix& l_cameraRotation)
{
	action_->ActionUpdate(deltaTime, l_position, l_velocity, l_prevposition, l_rotation, l_pose, l_motion, l_cameraRotation);
}

// ���̃A�N�V����ID�̐ݒ�ƃp�����[�^�[�̏�����
void PlayerActionBaseManager::NextAction(PlayerStateName & l_state, PlayerParameters& parameter)
{
	l_state = action_->Get_NextActionID();
	parameter.Set_StateTimer(0.0f);
}

// �o�^�A�N�V�����̃A�N�V�����ڍs�t���O�̎擾
bool PlayerActionBaseManager::Get_NextActionFlag() const
{
	return action_->Get_NextActionFlag();
}

// �o�^�A�N�V�����̎��̃A�N�V����ID�̎擾
PlayerStateName PlayerActionBaseManager::Get_NextActionID() const
{
	return action_->Get_NextActionID();
}
