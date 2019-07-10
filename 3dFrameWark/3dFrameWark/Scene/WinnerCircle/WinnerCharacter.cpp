#include "WinnerCharacter.h"

WinnerCharacter::WinnerCharacter()
{
}

WinnerCharacter::~WinnerCharacter()
{
}

// 勝利したキャラクター情報の初期化
void WinnerCharacter::initialize()
{
	m_winner = CharaID::None;
}

// 勝利したキャラクターの設定
void WinnerCharacter::Set_Winner(CharaID l_charaID)
{
	m_winner = l_charaID;
}

// 勝利したキャラクターの取得
CharaID WinnerCharacter::Get_Winner() const
{
	return m_winner;
}
