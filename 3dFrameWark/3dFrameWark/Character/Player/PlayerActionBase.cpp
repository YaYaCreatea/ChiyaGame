#include "PlayerActionBase.h"

// �A�N�V����������
void PlayerActionBase::ActionInitialize()
{
}

// �A�N�V�����X�V
void PlayerActionBase::ActionUpdate(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion,Matrix& l_cameraRotation)
{

}

// ���̃A�N�V�����ڍs�t���O�̎擾
bool PlayerActionBase::Get_NextActionFlag() const
{
	return m_nextAction;
}

// ���̃A�N�V����ID�̎擾
PlayerStateName PlayerActionBase::Get_NextActionID() const
{
	return m_nextActionID;
}
