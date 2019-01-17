#ifndef _TPS_CAMERA_H_
#define _TPS_CAMERA_H_

#include "../Actor/Actor.h"
#include "CameraStateID.h"

class TpsCamera :public Actor
{
public:
	explicit TpsCamera(IWorld& world, const Vector3& l_position, std::string l_targetName);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

private:
	void move(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

private:
	CameraStateID m_stateID;

	std::string m_targetName;

	Vector3 m_playerposition;
	Matrix m_playerrotate;

	Vector3 m_lookPos;
	Vector3 m_to_target;

	int inputx_, inputy_;
	float m_pitch;
	float m_backDis;

	float t;

	float m_yawAngle, m_pitchAngle;
};

#endif