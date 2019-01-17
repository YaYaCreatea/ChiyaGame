#ifndef _PLAYER_ACTION_BREAK_H_
#define _PLAYER_ACTION_BREAK_H_

#include "../PlayerActionBase.h"

class PlayerAction_Break :public PlayerActionBase
{
public:
	PlayerAction_Break(IWorld& world, PlayerParameters& parameter);
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime,
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion, Matrix& l_cameraRotation)override;

private:
	bool m_isSpawn;
	bool m_isCombo;
};

#endif