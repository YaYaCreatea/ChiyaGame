#include "CharaSelect.h"

#include "../../assetsID/AssetsID.h"

#include "../../Graphics2D/Graphics2D.h"
#include "../../Sound/Sound.h"

CharaSelect::CharaSelect(CharacterSelecter& l_selecter, SceneParameters & l_sceneParameters, StartUpLoad & l_load)
	:charaDecision_{ l_selecter }
{
	charaSelecter_ = &l_selecter;
	sceneParameters_ = &l_sceneParameters;
	load_ = &l_load;
}

void CharaSelect::start()
{
	m_isEnd = false;

	// �L�����N�^�[�Z���N�g��񏉊���
	charaSelecter_->initialize();

	// �L�����N�^�[�Z���N�g���䏉����
	charaDecision_.Initialize();

	m_sceneEndTimer = 120.0f;

	Sound::play_bgm((int)SoundID_BGM::CharaSelect);
}

void CharaSelect::update(float deltaTime)
{
	switch (sceneParameters_->Get_NextSceneID())
	{
	//1on1�̎�
	case SceneID::GameDuel:
		DuelSelect(deltaTime);
		break;

	//4�l�ΐ�̎�
	case SceneID::GameFour:
		FourSelect(deltaTime);
		break;
	}
}

void CharaSelect::draw() const
{
	// �L�����N�^�[�̃A�C�R����`��
	DrawCharacterICO();

	// �L�����N�^�[�Z���N�g�A�C�R����`��
	charaDecision_.DrawDecisionICO_Duel();
	if (sceneParameters_->Get_NextSceneID() == SceneID::GameFour)
		charaDecision_.DrawDecisionICO_Four();
}

bool CharaSelect::is_end() const
{
	return m_isEnd;
}

SceneID CharaSelect::next() const
{
	return SceneID::GameLoad;
}

void CharaSelect::end()
{
	load_->UnLoad();
}

// 1on1���̃Z���N�g����
void CharaSelect::DuelSelect(float deltaTime)
{
	charaDecision_.Decision_Duel(deltaTime);

	// 1P,2P�����ɑI��ł�����
	if (DuelSelected())
	{
		if (m_sceneEndTimer <= 0.0f)
		{
			m_isEnd = true;
			return;
		}
		m_sceneEndTimer -= deltaTime;
	}
}

// 4�l�ΐ펞�̃Z���N�g����
void CharaSelect::FourSelect(float deltaTime)
{
	charaDecision_.Decision_Four(deltaTime);

	// 1P,2P,3P,4P�S�����ɑI��ł�����
	if (FourSelected())
	{
		if (m_sceneEndTimer <= 0.0f)
		{
			m_isEnd = true;
			return;
		}
		m_sceneEndTimer -= deltaTime;
	}
}

// �L�����N�^�[�̃A�C�R����`��
void CharaSelect::DrawCharacterICO() const
{
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectBack, Vector2::Zero);
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectChiya, Vector2{ 50.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectRize, Vector2{ 350.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectSyaro, Vector2{ 650.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectCocoa, Vector2{ 950.0f,150.0f });
}

// 1P,2P�����ɑI��ł�����
bool CharaSelect::DuelSelected() const
{
	if (charaSelecter_->Get_1PChara() != CharaID::None
		&&charaSelecter_->Get_2PChara() != CharaID::None)
		return true;

	else
		return false;
}

// 1P,2P,3P,4P�S�����ɑI��ł�����
bool CharaSelect::FourSelected() const
{
	if (charaSelecter_->Get_1PChara() != CharaID::None
		&&charaSelecter_->Get_2PChara() != CharaID::None
		&&charaSelecter_->Get_3PChara() != CharaID::None
		&&charaSelecter_->Get_4PChara() != CharaID::None)
		return true;

	else
		return false;
}