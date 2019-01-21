#ifndef _PLAYER_PARAMETERS_H_
#define _PLAYER_PARAMETERS_H_

#include <string>

#include "../../ActorGroupManager/ActorGroup.h"

class PlayerParameters
{
public:
	PlayerParameters();
	void Initialize(std::string l_name);

	void Set_StateTimer(float l_state_timer);
	void Add_StateTimer(float l_state_timer);
	float Get_StateTimer()const;

	void Set_EndTime(float l_end_time);
	float Get_EndTime()const;

	float Get_Gravity()const;

	void Set_MyGroup(ActorGroup l_myGoup);
	ActorGroup Get_MyGroup()const;

	std::string Get_Name()const;

private:
	ActorGroup m_myGroup;

	std::string m_name{};

	const float WALKSPEED{ 1.0f };
	const float GRAVITY{ -0.04f };
	float m_state_timer;
	float m_end_time;

};

#endif