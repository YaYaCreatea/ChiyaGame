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

	// �t�F�[�h�p�����[�^������
	fead_.Initialize();

	// �C���v�b�g�̏�����
	input_.initialize(DX_INPUT_PAD1);

	// �J�����̏�����
	camera_.initialize();

	Sound::play_bgm((int)SoundID_BGM::ModeSelect);
}

void ModeSelect::update(float deltaTime)
{
	if (!fead_.IsFead())
		input_.update();

	// �J�����̍X�V
	camera_.update(deltaTime);

	// ���[�h�̌���
	if (input_.Trigger(PAD_INPUT_1))
	{
		Sound::play_se((int)SoundID_SE::SystemSelect);
		m_isEnd = true;
	}

	switch (m_modeID)
	{
	//�I��ł��郂�[�h��1on1�̎�
	case ModeID::Duel:
		if (input_.Trigger(PAD_INPUT_RIGHT))
		{
			Sound::play_se((int)SoundID_SE::SystemCursor);
			sceneParameters_->Set_NextSceneID(SceneID::GameFour);
			m_modeID = ModeID::Four;
		}
		break;
	//�I��ł��郂�[�h��4�l�ΐ�̎�
	case ModeID::Four:
		if (input_.Trigger(PAD_INPUT_LEFT))
		{
			Sound::play_se((int)SoundID_SE::SystemCursor);
			sceneParameters_->Set_NextSceneID(SceneID::GameDuel);
			m_modeID = ModeID::Duel;
		}
		break;
	}

	// �t�F�[�h�A�E�g
	fead_.FeadOut(deltaTime);
}

void ModeSelect::draw() const
{
	// �w�i�̕`��
	camera_.drawBack();

	switch (m_modeID)
	{
	//�I��ł��郂�[�h��1on1�̎�
	case ModeID::Duel:
		Graphics2D::draw_sprite((int)SpriteID::Mode1on1_Act, Vector2::Zero);
		Graphics2D::draw_sprite((int)SpriteID::ModeFour_Dact, Vector2{ 640.0f,0.0f });
		break;
	//�I��ł��郂�[�h��4�l�ΐ�̎�
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
