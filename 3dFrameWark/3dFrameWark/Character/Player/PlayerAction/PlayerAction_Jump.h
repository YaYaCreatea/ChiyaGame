#ifndef _PLAYER_ACTION_JUMP_H_
#define _PLAYER_ACTION_JUMP_H_

#include "../PlayerActionBase.h"

enum class JumpState
{
	Stand,
	Jumping,
	Landing,
};

class PlayerAction_Jump :public PlayerActionBase
{
public:
	PlayerAction_Jump(IWorld& world, PlayerParameters& parameter);
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime,
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion, Matrix& l_cameraRotation)override;

private:
	JumpState m_jumpState;
};

#endif