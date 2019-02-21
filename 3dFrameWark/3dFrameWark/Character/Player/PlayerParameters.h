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

	//���b�N�I���֘A�֐�
	void Set_LockOnDirection(Vector3 l_direction);
	void LockOnDirectionNormlize();
	Vector3 Get_LockOnDirection()const;
	void LockOn(bool l_isLockOn);
	bool Get_IsLockOn()const;

	void Set_DistanceNear(float l_distance);
	void Set_DistanceToChiya(float l_distance);
	void Set_DistanceToRize(float l_distance);
	void Set_DistanceToSyaro(float l_distance);
	void Set_DistanceToCocoa(float l_distance);

	float Get_DistanceNear()const;
	float Get_DistanceToChiya()const;
	float Get_DistanceToRize()const;
	float Get_DistanceToSyaro()const;
	float Get_DistanceToCocoa()const;


	//�_�E���֘A�֐�
	void DidDown();
	bool Get_IsDown()const;

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

	Vector3 m_lockOnDirection;
	float m_distanceNear;
	float m_distanceToChiya;
	float m_distanceToRize;
	float m_distanceToSyaro;
	float m_distanceToCocoa;
	bool m_isLockOn;

	bool m_isDown;

};

#endif