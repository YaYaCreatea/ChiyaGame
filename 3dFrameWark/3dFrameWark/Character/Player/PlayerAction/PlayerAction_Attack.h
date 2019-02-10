#ifndef _PLAYER_ACTION_ATTACK_H_
#define _PLAYER_ACTION_ATTACK_H_

#include "../PlayerActionBase.h"

class PlayerAction_Attack :public PlayerActionBase
{
public:
	PlayerAction_Attack(IWorld& world, PlayerParameters& parameter, InputState& input);
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime,
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion, Matrix& l_cameraRotation)override;

private:
	bool m_isSpawn;
	bool m_isCombo;
	Vector3 m_direction;
};

#endif