#ifndef _FOUR_CAMERA_H_
#define _FOUR_CAMERA_H_

#include "../../Actor/Actor.h"
#include "../CameraStateID.h"

#include "../../ActorGroupManager/ActorGroup.h"

#include "../../Graphics3D/Graphics3D.h"

class FourCamera :public Actor
{
public:
	explicit FourCamera(
		IWorld& world, 
		const Vector3& l_position, float l_yawAngle, 
		std::string l_targetName, int l_numPlayer);

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

	int m_numPlayer;
	int m_inputX, m_inputY;
	float m_pitch;
	float m_backDis;

	float t;

	float m_yawAngle, m_pitchAngle;

	ActorGroup m_group;
};

#endif