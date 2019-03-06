#include "Title.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"
#include "../../Sound/Sound.h"

void Title::start()
{
	m_isEnd = false;
	m_isNext = false;
	input_.initialize(DX_INPUT_PAD1);

	performance_.Initialize();
	fead_.Initialize(0);

	Sound::play_bgm((int)SoundID_BGM::Title);
}

void Title::update(float deltaTime)
{
	input_.update();
	if (input_.Trigger(PAD_INPUT_1)
		&& performance_.Is_Complete()
		&& !m_isNext)
	{
		Sound::play_se((int)SoundID_SE::SystemStart);
		m_isNext = true;
	}

	if (m_isNext)
	{
		if (!fead_.IsFead())
		{
			m_isEnd = true;
			return;
		}
		fead_.FeadIn(deltaTime);
	}

	performance_.Update(deltaTime);
}

void Title::draw() const
{
	performance_.Draw();
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
