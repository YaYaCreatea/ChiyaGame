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

	charaSelecter_->initialize();

	charaDecision_.Initialize();

	m_sceneEndTimer = 120.0f;

	Sound::play_bgm((int)SoundID_BGM::CharaSelect);
}

void CharaSelect::update(float deltaTime)
{
	switch (sceneParameters_->Get_NextSceneID())
	{
	case SceneID::GameDuel:
		DuelSelect(deltaTime);
		break;
	case SceneID::GameFour:
		FourSelect(deltaTime);
		break;
	}
}

void CharaSelect::draw() const
{
	DrawCharacterICO();

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

void CharaSelect::DuelSelect(float deltaTime)
{
	charaDecision_.Decision_Duel(deltaTime);

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

void CharaSelect::FourSelect(float deltaTime)
{
	charaDecision_.Decision_Four(deltaTime);

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

void CharaSelect::DrawCharacterICO() const
{
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectBack, Vector2::Zero);
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectChiya, Vector2{ 50.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectRize, Vector2{ 350.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectSyaro, Vector2{ 650.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectCocoa, Vector2{ 950.0f,150.0f });
}

bool CharaSelect::DuelSelected() const
{
	if (charaSelecter_->Get_1PChara() != CharaID::None
		&&charaSelecter_->Get_2PChara() != CharaID::None)
		return true;

	else
		return false;
}

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