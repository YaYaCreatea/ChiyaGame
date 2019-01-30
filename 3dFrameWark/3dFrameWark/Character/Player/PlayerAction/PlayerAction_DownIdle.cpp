#include "PlayerAction_DownIdle.h"

#include "../../../World/IWorld.h"
#include "../PlayerParameters.h"

PlayerAction_DownIdle::PlayerAction_DownIdle(IWorld & world, PlayerParameters & parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_DownIdle::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;	
}

void PlayerAction_DownIdle::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	parameters_->DidDown();

	if (parameters_->Get_Name() == "Chiya")
		l_motion = (int)ChiyaAnmID::DownIdle;
	else if (parameters_->Get_Name() == "Rize")
		l_motion = (int)RizeAnmID::DownIdle;
	else if (parameters_->Get_Name() == "Syaro")
		l_motion = (int)SyaroAnmID::DownIdle;
	else if (parameters_->Get_Name() == "Cocoa")
		l_motion = (int)CocoaAnmID::DownIdle;
}
