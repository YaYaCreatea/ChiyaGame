#include "CharacterSelecter.h"

CharacterSelecter::CharacterSelecter()
{
}

CharacterSelecter::~CharacterSelecter()
{
}

// キャラクターセレクト情報初期化
void CharacterSelecter::initialize()
{
	m_1P = CharaID::None;
	m_2P = CharaID::None;
	m_3P = CharaID::None;
	m_4P = CharaID::None;

	m_chiyaAlready = false;
	m_rizeAlready = false;
	m_syaroAlready = false;
	m_cocoaAlready = false;
}

// 1Pのキャラクターの設定
void CharacterSelecter::Set_1PChara(CharaID l_1P)
{
	m_1P = l_1P;
}

// 1Pのキャラクターの取得
CharaID CharacterSelecter::Get_1PChara() const
{
	return m_1P;
}

// 2Pのキャラクターの設定
void CharacterSelecter::Set_2PChara(CharaID l_2P)
{
	m_2P = l_2P;
}

// 2Pのキャラクターの取得
CharaID CharacterSelecter::Get_2PChara() const
{
	return m_2P;
}

// 3Pのキャラクターの設定
void CharacterSelecter::Set_3PChara(CharaID l_3P)
{
	m_3P = l_3P;
}

// 3Pのキャラクターの取得
CharaID CharacterSelecter::Get_3PChara() const
{
	return m_3P;
}

// 4Pのキャラクターの設定
void CharacterSelecter::Set_4PChara(CharaID l_4P)
{
	m_4P = l_4P;
}

// 4Pのキャラクターの取得
CharaID CharacterSelecter::Get_4PChara() const
{
	return m_4P;
}

// 千夜を選ぶ
void CharacterSelecter::SelectionChiya()
{
	m_chiyaAlready = true;
}

// 千夜が既に選ばれているか取得
bool CharacterSelecter::Get_SelectionChiya() const
{
	return m_chiyaAlready;
}

// リゼを選ぶ
void CharacterSelecter::SelectionRize()
{
	m_rizeAlready = true;
}

// リゼが既に選ばれているか取得
bool CharacterSelecter::Get_SelectionRize() const
{
	return m_rizeAlready;
}

// シャロを選ぶ
void CharacterSelecter::SelectionSyaro()
{
	m_syaroAlready = true;
}

// シャロが既に選ばれているか取得
bool CharacterSelecter::Get_SelectionSyaro() const
{
	return m_syaroAlready;
}

// ココアを選ぶ
void CharacterSelecter::SelectionCocoa()
{
	m_cocoaAlready = true;
}

// ココアが既に選ばれているか取得
bool CharacterSelecter::Get_SelectionCocoa() const
{
	return m_cocoaAlready;
}
