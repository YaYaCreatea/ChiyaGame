#include "SceneParameters.h"

SceneParameters::SceneParameters()
{
}

SceneParameters::~SceneParameters()
{
}

void SceneParameters::initialize()
{
	m_nextSceneID = SceneID::Title;
}

void SceneParameters::Set_NextSceneID(SceneID l_id)
{
	m_nextSceneID = l_id;
}

SceneID SceneParameters::Get_NextSceneID() const
{
	return m_nextSceneID;
}
