#ifndef _PLAYER_ACTION_IDLE_H_
#define _PLAYER_ACTION_IDLE_H_

#include "../PlayerActionBase.h"

class PlayerAction_Idle :public PlayerActionBase
{
public:
	PlayerAction_Idle(IWorld& world, PlayerParameters& parameter,InputState& input);
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime, 
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion,Matrix& l_cameraRotation)override;
};

#endif