#include "PlayerParameters.h"

#include "../../Utility/MathHelper/MathHelper.h"

PlayerParameters::PlayerParameters()
{
}

//������
void PlayerParameters::Initialize(std::string l_name, int l_Hp)
{
	m_name = l_name;
	m_Hp = l_Hp;
	m_HpMax = l_Hp;
	m_state_timer = 0.0f;
	m_end_time = 0.0f;
	m_breakDirection = Vector3::Zero;
	m_lockOnDirection = Vector3::Zero;
	m_distanceNear = 0.0f;
	m_distanceToChiya = 0.0f;
	m_distanceToRize = 0.0f;
	m_distanceToSyaro = 0.0f;
	m_distanceToCocoa = 0.0f;
	m_isLockOn = true;
	m_isDown = false;
}

// �A�j���[�V������ԃ^�C�}�[�ݒ�
void PlayerParameters::Set_StateTimer(float l_state_timer)
{
	m_state_timer = l_state_timer;
}

// �A�j���[�V������ԃ^�C�}�[�ǉ�
void PlayerParameters::Add_StateTimer(float l_state_timer)
{
	m_state_timer += l_state_timer;
}

// �A�j���[�V������ԃ^�C�}�[�擾
float PlayerParameters::Get_StateTimer() const
{
	return m_state_timer;
}

// �A�j���[�V�����I�����Ԑݒ�
void PlayerParameters::Set_EndTime(float l_end_time)
{
	m_end_time = l_end_time;
}

// �A�j���[�V�����I�����Ԏ擾
float PlayerParameters::Get_EndTime() const
{
	return m_end_time;
}

// �d�͂̎擾
float PlayerParameters::Get_Gravity() const
{
	return GRAVITY;
}

// ������Actor�O���[�v�̐ݒ�
void PlayerParameters::Set_MyGroup(ActorGroup l_myGoup)
{
	m_myGroup = l_myGoup;
}

// ������Actor�O���[�v�̎擾
ActorGroup PlayerParameters::Get_MyGroup() const
{
	return m_myGroup;
}

// ���O�̎擾
std::string PlayerParameters::Get_Name() const
{
	return m_name;
}

// HP(�_���[�W����)
void PlayerParameters::Damage_HP(int l_damageHp)
{
	m_Hp = MathHelper::ClampInt(m_Hp - l_damageHp, 0, m_HpMax);
}

// ���݂�HP�̎擾
int PlayerParameters::Get_HP() const
{
	return m_Hp;
}

// HP�̍ő�l�̎擾
int PlayerParameters::Get_MaxHP() const
{
	return m_HpMax;
}

// Break�����̐ݒ�
void PlayerParameters::Set_BreakDirection(Vector3 l_direction)
{
	m_breakDirection = l_direction;
}

// Break�����̎擾
Vector3 PlayerParameters::Get_BreakDirection() const
{
	return m_breakDirection;
}

// ���b�N�I�������̐ݒ�
void PlayerParameters::Set_LockOnDirection(Vector3 l_direction)
{
	m_lockOnDirection = l_direction;
}

// ���b�N�I���������K��
void PlayerParameters::LockOnDirectionNormlize()
{
	m_lockOnDirection.Normalize();
}

// ���b�N�I�������̎擾
Vector3 PlayerParameters::Get_LockOnDirection() const
{
	return m_lockOnDirection;
}

// ���b�N�I����Ԃ̐ݒ�
void PlayerParameters::LockOn(bool l_isLockOn)
{
	m_isLockOn = l_isLockOn;
}

// ���b�N�I����Ԃ̎擾
bool PlayerParameters::Get_IsLockOn() const
{
	return m_isLockOn;
}

// ��ԋ߂������̐ݒ�
void PlayerParameters::Set_DistanceNear(float l_distance)
{
	m_distanceNear = l_distance;
}

// ���܂ł̋����̐ݒ�
void PlayerParameters::Set_DistanceToChiya(float l_distance)
{
	m_distanceToChiya = l_distance;
}

// ���[�܂ł̋����̐ݒ�
void PlayerParameters::Set_DistanceToRize(float l_distance)
{
	m_distanceToRize = l_distance;
}

// �V�����܂ł̋����̐ݒ�
void PlayerParameters::Set_DistanceToSyaro(float l_distance)
{
	m_distanceToSyaro = l_distance;
}

// �R�R�A�܂ł̋����̐ݒ�
void PlayerParameters::Set_DistanceToCocoa(float l_distance)
{
	m_distanceToCocoa = l_distance;
}

// ��ԋ߂������̎擾
float PlayerParameters::Get_DistanceNear() const
{
	return m_distanceNear;
}

// ���܂ł̋����̎擾
float PlayerParameters::Get_DistanceToChiya() const
{
	return m_distanceToChiya;
}

// ���[�܂ł̋����̎擾
float PlayerParameters::Get_DistanceToRize() const
{
	return m_distanceToRize;
}

// �V�����܂ł̋����̎擾
float PlayerParameters::Get_DistanceToSyaro() const
{
	return m_distanceToSyaro;
}

// �R�R�A�܂ł̋����̎擾
float PlayerParameters::Get_DistanceToCocoa() const
{
	return m_distanceToCocoa;
}

// �_�E���������̐ݒ�
void PlayerParameters::DidDown()
{
	m_isDown = true;
}

// �_�E���������̎擾
bool PlayerParameters::Get_IsDown() const
{
	return m_isDown;
}
