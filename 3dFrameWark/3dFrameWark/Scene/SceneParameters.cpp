#include "SceneParameters.h"

SceneParameters::SceneParameters()
{
}

SceneParameters::~SceneParameters()
{
}

// �V�[�����̏�����
void SceneParameters::initialize()
{
	m_nextSceneID = SceneID::Title;
}

// ���̃V�[��ID�̐ݒ�
void SceneParameters::Set_NextSceneID(SceneID l_id)
{
	m_nextSceneID = l_id;
}

// ���̃V�[��ID�̎擾
SceneID SceneParameters::Get_NextSceneID() const
{
	return m_nextSceneID;
}
