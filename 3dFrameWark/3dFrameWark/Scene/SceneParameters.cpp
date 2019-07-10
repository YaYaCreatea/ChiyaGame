#include "SceneParameters.h"

SceneParameters::SceneParameters()
{
}

SceneParameters::~SceneParameters()
{
}

// シーン情報の初期化
void SceneParameters::initialize()
{
	m_nextSceneID = SceneID::Title;
}

// 次のシーンIDの設定
void SceneParameters::Set_NextSceneID(SceneID l_id)
{
	m_nextSceneID = l_id;
}

// 次のシーンIDの取得
SceneID SceneParameters::Get_NextSceneID() const
{
	return m_nextSceneID;
}
