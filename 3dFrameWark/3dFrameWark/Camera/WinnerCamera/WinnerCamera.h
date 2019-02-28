#ifndef _WINNER_CAMERA_H_
#define _WINNER_CAMERA_H_

#include "../../Actor/Actor.h"

#include "../../ActorGroupManager/ActorGroup.h"

#include "../../Graphics3D/Graphics3D.h"

#include "CameraWork/ChiyaWork.h"
#include "CameraWork/SyaroWork.h"

class WinnerCamera :public Actor
{
public:
	explicit WinnerCamera(
		IWorld& world,
		const Vector3& l_position, float l_yawAngle,
		std::string l_targetName);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;


private:
	ChiyaWork chiyaWork_;
	SyaroWork syaroWork_;

	std::string m_targetName;

	Vector3 m_playerposition;
	Matrix m_playerrotate;

	Vector3 m_lookPos;

	float m_backDis;

	float t;

	float m_yawAngle, m_pitchAngle;

	ActorGroup m_group;
};

#endif