#include "Title.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"
#include "../../Sound/Sound.h"

void Title::start()
{
	m_isEnd = false;
	m_isNext = false;

	// インプットの初期化
	input_.initialize(DX_INPUT_PAD1);

	// タイトル演出の初期化
	performance_.Initialize();

	// フェードパラメータ初期化
	fead_.Initialize(0);

	Sound::play_bgm((int)SoundID_BGM::Title);
}

void Title::update(float deltaTime)
{
	// インプットの更新
	input_.update();

	// Press A Start制御
	if (input_.Trigger(PAD_INPUT_1)
		&& performance_.Is_Complete()
		&& !m_isNext)
	{
		Sound::play_se((int)SoundID_SE::SystemStart);
		m_isNext = true;
	}

	// フェードイン制御へ
	if (m_isNext)
	{
		if (!fead_.IsFead())
		{
			m_isEnd = true;
			return;
		}
		fead_.FeadIn(deltaTime);
	}

	// タイトル演出の更新
	performance_.Update(deltaTime);
}

void Title::draw() const
{
	// タイトル演出の描画
	performance_.Draw();
	// 暗転画像の描画
	fead_.DrawBack();
}

bool Title::is_end() const
{
	return m_isEnd;
}

SceneID Title::next() const
{
	return SceneID::Select;
}

void Title::end()
{
}
