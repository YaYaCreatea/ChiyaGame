#ifndef _PLAYER_PARAMETERS_H_
#define _PLAYER_PARAMETERS_H_

#include <string>

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../Utility/Vector3/Vector3.h"

class PlayerParameters
{
public:
	PlayerParameters();
	//������
	void Initialize(std::string l_name, int l_Hp);

	//�A�j���[�V������ԃ^�C�}�[�֘A�֐�
	void Set_StateTimer(float l_state_timer);
	void Add_StateTimer(float l_state_timer);
	float Get_StateTimer()const;

	//�A�j���[�V�����I�����Ԋ֘A�֐�
	void Set_EndTime(float l_end_time);
	float Get_EndTime()const;

	//�d�͂̎擾
	float Get_Gravity()const;

	//������Actor�O���[�v�֘A�֐�
	void Set_MyGroup(ActorGroup l_myGoup);
	ActorGroup Get_MyGroup()const;

	//���O�̎擾
	std::string Get_Name()const;

	//HP�֘A�֐�
	void Damage_HP(int l_damageHp);
	int Get_HP()const;
	int Get_MaxHP()const;

	//Break�����֘A�֐�
	void Set_BreakDirection(Vector3 l_direction);
	Vector3 Get_BreakDirection()const;

private:
	ActorGroup m_myGroup;

	std::string m_name{};

	int m_Hp;
	int m_HpMax;

	const float WALKSPEED{ 1.0f };
	const float GRAVITY{ -0.04f };
	float m_state_timer;
	float m_end_time;

	Vector3 m_breakDirection;

};

#endif