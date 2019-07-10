#include "PlayerActionBase.h"

// アクション初期化
void PlayerActionBase::ActionInitialize()
{
}

// アクション更新
void PlayerActionBase::ActionUpdate(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion,Matrix& l_cameraRotation)
{

}

// 次のアクション移行フラグの取得
bool PlayerActionBase::Get_NextActionFlag() const
{
	return m_nextAction;
}

// 次のアクションIDの取得
PlayerStateName PlayerActionBase::Get_NextActionID() const
{
	return m_nextActionID;
}
