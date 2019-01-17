#ifndef _PLAYER_PARAMETERS_H_
#define _PLAYER_PARAMETERS_H_

class PlayerParameters
{
public:
	PlayerParameters();
	void Initialize();

	void Set_StateTimer(float l_state_timer);
	void Add_StateTimer(float l_state_timer);
	float Get_StateTimer()const;

	void Set_EndTime(float l_end_time);
	float Get_EndTime()const;

	float Get_Gravity()const;

private:
	const float WALKSPEED{ 1.0f };
	const float GRAVITY{ -0.04f };
	float m_state_timer;
	float m_end_time;

};

#endif