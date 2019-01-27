#ifndef _PLAYER_ACTION_MANAGER_H_
#define _PLAYER_ACTION_MANAGER_H_

#include "PlayerActionBase.h"
#include "PlayerActionPtr.h"

class PlayerParameters;

class PlayerActionBaseManager
{
public:
	PlayerActionBaseManager() = default;

	void add(const PlayerActionPtr& action);

	void initialize();

	void update(
		float deltaTime,
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
		Matrix l_pose, int& l_motion,
		Matrix& l_cameraRotation);

	void NextAction(PlayerStateName& l_state, PlayerParameters& parameter);

	bool Get_NextActionFlag()const;

	PlayerStateName Get_NextActionID()const;

	PlayerActionBaseManager(const PlayerActionBaseManager& other) = delete;
	PlayerActionBaseManager& operator=(const PlayerActionBaseManager& other) = delete;

private:
	PlayerActionPtr action_;
};

#endif