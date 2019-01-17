#include "PlayerActionBase.h"

void PlayerActionBase::ActionInitialize()
{
}

void PlayerActionBase::ActionUpdate(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion,Matrix& l_cameraRotation)
{

}

bool PlayerActionBase::Get_NextActionFlag() const
{
	return m_nextAction;
}

PlayerStateName PlayerActionBase::Get_NextActionID() const
{
	return m_nextActionID;
}
