#include "PlayerActionBaseManager.h"

#include "PlayerParameters.h"

void PlayerActionBaseManager::add(const PlayerActionPtr & action)
{
	action_ = action;
}

void PlayerActionBaseManager::initialize()
{
	action_->ActionInitialize();
}

void PlayerActionBaseManager::update(
	float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
	Matrix l_pose, int& l_motion, Matrix& l_cameraRotation)
{
	action_->ActionUpdate(deltaTime, l_position, l_velocity, l_prevposition, l_rotation, l_pose, l_motion, l_cameraRotation);
}

void PlayerActionBaseManager::NextAction(PlayerStateName & l_state, PlayerParameters& parameter)
{
	l_state = action_->Get_NextActionID();
	parameter.Set_StateTimer(0.0f);
}

bool PlayerActionBaseManager::Get_NextActionFlag() const
{
	return action_->Get_NextActionFlag();
}

PlayerStateName PlayerActionBaseManager::Get_NextActionID() const
{
	return action_->Get_NextActionID();
}
