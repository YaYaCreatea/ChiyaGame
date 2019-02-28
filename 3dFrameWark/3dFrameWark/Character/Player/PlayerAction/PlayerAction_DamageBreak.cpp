#include "PlayerAction_DamageBreak.h"

#include "../../../World/IWorld.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../PlayerParameters.h"

#include "../../../Effect/HitEffect.h"

PlayerAction_DamageBreak::PlayerAction_DamageBreak(IWorld & world, PlayerParameters & parameter)
{
	world_ = &world;
	parameters_ = &parameter;
}

void PlayerAction_DamageBreak::ActionInitialize()
{
	m_nextAction = false;
	m_nextActionID = PlayerStateName::Idle;

	m_friction = 2.0f;
	m_isHit = false;
}

void PlayerAction_DamageBreak::ActionUpdate(float deltaTime, Vector3 & l_position, Vector3 & l_velocity, Vector3 & l_prevposition, Matrix & l_rotation, Matrix l_pose, int & l_motion, Matrix & l_cameraRotation)
{
	if (!m_isHit)
	{
		world_->add_actor(ActorGroup::Effect, new_actor<HitEffect>(l_position));
		m_isHit = true;
	}

	l_prevposition = l_position;
	Vector3 l_directionOffset{ -parameters_->Get_BreakDirection().x,0.0f,parameters_->Get_BreakDirection().z };

	l_rotation = Matrix::CreateLookAt(l_position, l_position + l_directionOffset, l_pose.Up());
	l_position += parameters_->Get_BreakDirection() * deltaTime;

	if (parameters_->Get_StateTimer() >= parameters_->Get_EndTime()*2.0f)
	{
		m_nextAction = true;
	}
}
