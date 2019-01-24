#ifndef _PLAYER_ACTION_BREAK_H_
#define _PLAYER_ACTION_BREAK_H_

#include "../PlayerActionBase.h"

enum class BreakState
{
	Ready,
	Charge,
	ChargeMax,
	Break
};

class PlayerAction_Break :public PlayerActionBase
{
public:
	PlayerAction_Break(IWorld& world, PlayerParameters& parameter, InputState& input);
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime,
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion, Matrix& l_cameraRotation)override;

private:
	BreakState m_breakState;
	bool m_isSpawn;
	float m_charge;
	
};

#endif