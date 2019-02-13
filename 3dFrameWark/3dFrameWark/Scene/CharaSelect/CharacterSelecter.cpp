#include "CharacterSelecter.h"

CharacterSelecter::CharacterSelecter()
{
}

CharacterSelecter::~CharacterSelecter()
{
}

void CharacterSelecter::initialize()
{
	m_1P = CharaID::None;
	m_2P = CharaID::None;
	m_3P = CharaID::None;
	m_4P = CharaID::None;
}

void CharacterSelecter::Set_1PChara(CharaID l_1P)
{
	m_1P = l_1P;
}

CharaID CharacterSelecter::Get_1PChara() const
{
	return m_1P;
}

void CharacterSelecter::Set_2PChara(CharaID l_2P)
{
	m_2P = l_2P;
}

CharaID CharacterSelecter::Get_2PChara() const
{
	return m_2P;
}

void CharacterSelecter::Set_3PChara(CharaID l_3P)
{
	m_3P = l_3P;
}

CharaID CharacterSelecter::Get_3PChara() const
{
	return m_3P;
}

void CharacterSelecter::Set_4PChara(CharaID l_4P)
{
	m_4P = l_4P;
}

CharaID CharacterSelecter::Get_4PChara() const
{
	return m_4P;
}
