#include "ToPlay.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../Graphics2D/Graphics2D.h"

ToPlay::ToPlay(SceneParameters& l_sceneParameters, PlayLoad& l_load)
{
	sceneParameters_ = &l_sceneParameters;
	load_ = &l_load;
}

void ToPlay::start()
{
	m_isEnd = false;
	m_nextTimer = 0.0f;

	//プレイモードのリソースロード
	load_->Load();
}

void ToPlay::update(float deltaTime)
{
	//読み込み完了後90秒後に移行
	if (GetASyncLoadNum() == 0)
	{
		if (m_nextTimer >= 90.0f)
			m_isEnd = true;
		m_nextTimer += deltaTime;
	}
}

void ToPlay::draw() const
{
	Graphics2D::draw_sprite((int)SpriteID::NLLogo, Vector2{ 500.0f,390.0f });

	//ゲージ
	Graphics2D::draw_sprite_rect(
		(int)SpriteID::LoadGauge, Vector2{ 420.0f,320.0f },
		0, 0, 450 - ((450 / load_->get_loadNum())*GetASyncLoadNum()), 40
	);
	Graphics2D::draw_sprite((int)SpriteID::LoadFrame, Vector2{ 420.0f,320.0f });
}

bool ToPlay::is_end() const
{
	return m_isEnd;
}

SceneID ToPlay::next() const
{
	//Duel or Four
	return sceneParameters_->Get_NextSceneID();
}

void ToPlay::end()
{
}
