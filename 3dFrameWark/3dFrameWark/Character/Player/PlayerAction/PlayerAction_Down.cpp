#include "PlayerAction_Down.h"

#include "../../../World/IWorld.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../PlayerParameters.h"

PlayerAction_Down::PlayerAction_Down(IWorld & world, PlayerParameters & parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_Down::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;
}

void PlayerAction_Down::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
}
