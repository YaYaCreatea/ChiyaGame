#include "WinnerCharacter.h"

WinnerCharacter::WinnerCharacter()
{
}

WinnerCharacter::~WinnerCharacter()
{
}

// ���������L�����N�^�[���̏�����
void WinnerCharacter::initialize()
{
	m_winner = CharaID::None;
}

// ���������L�����N�^�[�̐ݒ�
void WinnerCharacter::Set_Winner(CharaID l_charaID)
{
	m_winner = l_charaID;
}

// ���������L�����N�^�[�̎擾
CharaID WinnerCharacter::Get_Winner() const
{
	return m_winner;
}
