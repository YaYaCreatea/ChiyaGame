#include "PlayerActionBaseManager.h"

#include "PlayerParameters.h"

// アクションの追加
void PlayerActionBaseManager::add(const PlayerActionPtr & action)
{
	action_ = action;
}

// 登録アクションの初期化
void PlayerActionBaseManager::initialize()
{
	action_->ActionInitialize();
}

// 登録アクションの更新処理
void PlayerActionBaseManager::update(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion, Matrix& l_cameraRotation)
{
	action_->ActionUpdate(deltaTime, l_position, l_velocity, l_prevposition, l_rotation, l_pose, l_motion, l_cameraRotation);
}

// 次のアクションIDの設定とパラメーターの初期化
void PlayerActionBaseManager::NextAction(PlayerStateName & l_state, PlayerParameters& parameter)
{
	l_state = action_->Get_NextActionID();
	parameter.Set_StateTimer(0.0f);
}

// 登録アクションのアクション移行フラグの取得
bool PlayerActionBaseManager::Get_NextActionFlag() const
{
	return action_->Get_NextActionFlag();
}

// 登録アクションの次のアクションIDの取得
PlayerStateName PlayerActionBaseManager::Get_NextActionID() const
{
	return action_->Get_NextActionID();
}
