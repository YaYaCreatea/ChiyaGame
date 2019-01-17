#ifndef _PLAYER_ACTION_MOVE_H_
#define _PLAYER_ACTION_MOVE_H_

#include "../PlayerActionBase.h"

class PlayerAction_Move :public PlayerActionBase
{
public:
	PlayerAction_Move();
	virtual void ActionInitialize()override;
	virtual void ActionUpdate(
		float deltaTime, 
		Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation, Matrix l_pose,
		int& l_motion, Matrix& l_cameraRotation)override;

private:
	//à⁄ìÆó 
	void input_velocity(
		Vector3& l_velocity,
		float l_forward_speed, float l_side_speed, 
		Matrix& l_cameraRotation);

	//êUÇËå¸Ç´
	void face_to_orientation(
		float deltaTime, 
		Vector3& l_position, Vector3& l_prevposition,Matrix& l_rotation, Vector3 l_upAxis);

private:
	const float WALKSPEED{ 1.0f };
};

#endif