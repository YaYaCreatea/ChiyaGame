#include "WinnerCharacter.h"

WinnerCharacter::WinnerCharacter()
{
}

WinnerCharacter::~WinnerCharacter()
{
}

void WinnerCharacter::initialize()
{
	m_winner = CharaID::Cocoa;
}

void WinnerCharacter::Set_Winner(CharaID l_charaID)
{
	m_winner = l_charaID;
}

CharaID WinnerCharacter::Get_Winner() const
{
	return m_winner;
}
