#include "Title.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"
#include "../../Sound/Sound.h"

void Title::start()
{
	m_isEnd = false;
	m_isNext = false;

	// �C���v�b�g�̏�����
	input_.initialize(DX_INPUT_PAD1);

	// �^�C�g�����o�̏�����
	performance_.Initialize();

	// �t�F�[�h�p�����[�^������
	fead_.Initialize(0);

	Sound::play_bgm((int)SoundID_BGM::Title);
}

void Title::update(float deltaTime)
{
	// �C���v�b�g�̍X�V
	input_.update();

	// Press A Start����
	if (input_.Trigger(PAD_INPUT_1)
		&& performance_.Is_Complete()
		&& !m_isNext)
	{
		Sound::play_se((int)SoundID_SE::SystemStart);
		m_isNext = true;
	}

	// �t�F�[�h�C�������
	if (m_isNext)
	{
		if (!fead_.IsFead())
		{
			m_isEnd = true;
			return;
		}
		fead_.FeadIn(deltaTime);
	}

	// �^�C�g�����o�̍X�V
	performance_.Update(deltaTime);
}

void Title::draw() const
{
	// �^�C�g�����o�̕`��
	performance_.Draw();
	// �Ó]�摜�̕`��
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
