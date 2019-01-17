#ifndef _PLAYER_ACTION_BASE_H_
#define _PLAYER_ACTION_BASE_H_

#include "PlayerStateName.h"
#include "../../ActorGroupManager/ActorGroup.h"

#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Vector2/Vector2.h"
#include "../../Utility/Matrix/Matrix.h"

#include "../../Utility/Input/GamePad/GamePad.h"

class IWorld;
class PlayerParameters;

class PlayerActionBase
{
public:
	PlayerActionBase() = default;
	virtual ~PlayerActionBase() {}
	virtual void ActionInitialize();
	virtual void ActionUpdate(
		float deltaTime, Vector3& l_position, Vector3& l_velocity, Vector3& l_prevposition, Matrix& l_rotation,
		Matrix l_pose, int& l_motion,
		Matrix& l_cameraRotation);

	bool Get_NextActionFlag()const;

	PlayerStateName Get_NextActionID()const;

	PlayerActionBase(const PlayerActionBase& other) = delete;
	PlayerActionBase& operator=(const PlayerActionBase& other) = delete;

protected:
	IWorld* world_{ nullptr };
	PlayerParameters* parameters_{ nullptr };

	bool m_nextAction;
	PlayerStateName m_nextActionID;
};

#endif