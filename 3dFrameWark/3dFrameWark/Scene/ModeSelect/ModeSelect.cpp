#include "ModeSelect.h"

#include "../../assetsID/AssetsID.h"

#include "../../Utility/MathHelper/MathHelper.h"
#include "../../Utility/Vector2/Vector2.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../Sound/Sound.h"

ModeSelect::ModeSelect(SceneParameters & l_sceneParameters, StartUpLoad& l_load)
{
	sceneParameters_ = &l_sceneParameters;
	load_ = &l_load;
}

void ModeSelect::start()
{
	m_modeID = ModeID::Duel;
	sceneParameters_->Set_NextSceneID(SceneID::GameDuel);

	m_isEnd = false;

	// フェードパラメータ初期化
	fead_.Initialize();

	// インプットの初期化
	input_.initialize(DX_INPUT_PAD1);

	// カメラの初期化
	camera_.initialize();

	Sound::play_bgm((int)SoundID_BGM::ModeSelect);
}

void ModeSelect::update(float deltaTime)
{
	if (!fead_.IsFead())
		input_.update();

	// カメラの更新
	camera_.update(deltaTime);

	// モードの決定
	if (input_.Trigger(PAD_INPUT_1))
	{
		Sound::play_se((int)SoundID_SE::SystemSelect);
		m_isEnd = true;
	}

	switch (m_modeID)
	{
	//選んでいるモードが1on1の時
	case ModeID::Duel:
		if (input_.Trigger(PAD_INPUT_RIGHT))
		{
			Sound::play_se((int)SoundID_SE::SystemCursor);
			sceneParameters_->Set_NextSceneID(SceneID::GameFour);
			m_modeID = ModeID::Four;
		}
		break;
	//選んでいるモードが4人対戦の時
	case ModeID::Four:
		if (input_.Trigger(PAD_INPUT_LEFT))
		{
			Sound::play_se((int)SoundID_SE::SystemCursor);
			sceneParameters_->Set_NextSceneID(SceneID::GameDuel);
			m_modeID = ModeID::Duel;
		}
		break;
	}

	// フェードアウト
	fead_.FeadOut(deltaTime);
}

void ModeSelect::draw() const
{
	// 背景の描画
	camera_.drawBack();

	switch (m_modeID)
	{
	//選んでいるモードが1on1の時
	case ModeID::Duel:
		Graphics2D::draw_sprite((int)SpriteID::Mode1on1_Act, Vector2::Zero);
		Graphics2D::draw_sprite((int)SpriteID::ModeFour_Dact, Vector2{ 640.0f,0.0f });
		break;
	//選んでいるモードが4人対戦の時
	case ModeID::Four:
		Graphics2D::draw_sprite((int)SpriteID::Mode1on1_Dact, Vector2::Zero);
		Graphics2D::draw_sprite((int)SpriteID::ModeFour_Act, Vector2{ 640.0f,0.0f });
		break;
	}

	fead_.DrawBack();
}

bool ModeSelect::is_end() const
{
	return m_isEnd;
}

SceneID ModeSelect::next() const
{
	return SceneID::CharaSelect;
}

void ModeSelect::end()
{
	camera_.finalize();
}
