#include "CharacterSelecter.h"

CharacterSelecter::CharacterSelecter()
{
}

CharacterSelecter::~CharacterSelecter()
{
}

// �L�����N�^�[�Z���N�g��񏉊���
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

// 1P�̃L�����N�^�[�̐ݒ�
void CharacterSelecter::Set_1PChara(CharaID l_1P)
{
	m_1P = l_1P;
}

// 1P�̃L�����N�^�[�̎擾
CharaID CharacterSelecter::Get_1PChara() const
{
	return m_1P;
}

// 2P�̃L�����N�^�[�̐ݒ�
void CharacterSelecter::Set_2PChara(CharaID l_2P)
{
	m_2P = l_2P;
}

// 2P�̃L�����N�^�[�̎擾
CharaID CharacterSelecter::Get_2PChara() const
{
	return m_2P;
}

// 3P�̃L�����N�^�[�̐ݒ�
void CharacterSelecter::Set_3PChara(CharaID l_3P)
{
	m_3P = l_3P;
}

// 3P�̃L�����N�^�[�̎擾
CharaID CharacterSelecter::Get_3PChara() const
{
	return m_3P;
}

// 4P�̃L�����N�^�[�̐ݒ�
void CharacterSelecter::Set_4PChara(CharaID l_4P)
{
	m_4P = l_4P;
}

// 4P�̃L�����N�^�[�̎擾
CharaID CharacterSelecter::Get_4PChara() const
{
	return m_4P;
}

// ����I��
void CharacterSelecter::SelectionChiya()
{
	m_chiyaAlready = true;
}

// ��邪���ɑI�΂�Ă��邩�擾
bool CharacterSelecter::Get_SelectionChiya() const
{
	return m_chiyaAlready;
}

// ���[��I��
void CharacterSelecter::SelectionRize()
{
	m_rizeAlready = true;
}

// ���[�����ɑI�΂�Ă��邩�擾
bool CharacterSelecter::Get_SelectionRize() const
{
	return m_rizeAlready;
}

// �V������I��
void CharacterSelecter::SelectionSyaro()
{
	m_syaroAlready = true;
}

// �V���������ɑI�΂�Ă��邩�擾
bool CharacterSelecter::Get_SelectionSyaro() const
{
	return m_syaroAlready;
}

// �R�R�A��I��
void CharacterSelecter::SelectionCocoa()
{
	m_cocoaAlready = true;
}

// �R�R�A�����ɑI�΂�Ă��邩�擾
bool CharacterSelecter::Get_SelectionCocoa() const
{
	return m_cocoaAlready;
}
