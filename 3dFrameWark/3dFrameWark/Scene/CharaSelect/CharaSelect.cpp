#include "CharaSelect.h"

#include "../../assetsID/AssetsID.h"

#include "../../Graphics2D/Graphics2D.h"
#include "../../Sound/Sound.h"

CharaSelect::CharaSelect(CharacterSelecter& l_selecter, SceneParameters & l_sceneParameters, StartUpLoad & l_load)
{
	charaSelecter_ = &l_selecter;
	sceneParameters_ = &l_sceneParameters;
	load_ = &l_load;
}

void CharaSelect::start()
{
	m_isEnd = false;
	input1P_.initialize(DX_INPUT_PAD1);
	input2P_.initialize(DX_INPUT_PAD2);
	input3P_.initialize(DX_INPUT_PAD3);
	input4P_.initialize(DX_INPUT_PAD4);

	charaSelecter_->initialize();

	m_1Pposition = Vector2::Zero;
	m_2Pposition = Vector2{ 1180.0f,0.0f };
	m_3Pposition = Vector2{ 0.0f,620.0f };
	m_4Pposition = Vector2{ 1180.0f,620.0f };

	m_icoSpeed = 10.0f;
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

	BaseSelectUpdate(deltaTime);
}

void CharaSelect::draw() const
{
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectBack, Vector2::Zero);
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectChiya, Vector2{ 50.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectRize, Vector2{ 350.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectSyaro, Vector2{ 650.0f,150.0f });
	Graphics2D::draw_sprite((int)SpriteID::CharaSelectCocoa, Vector2{ 950.0f,150.0f });

	if (charaSelecter_->Get_1PChara() == CharaID::None)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_1_D, m_1Pposition);
	else if (charaSelecter_->Get_1PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_1_0, m_1Pposition);
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_1_1, m_1Pposition);
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_1_2, m_1Pposition);
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_1_3, m_1Pposition);

	if (charaSelecter_->Get_2PChara() == CharaID::None)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_2_D, m_2Pposition);
	else if (charaSelecter_->Get_2PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_2_0, m_2Pposition);
	else if (charaSelecter_->Get_2PChara() == CharaID::Rize)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_2_1, m_2Pposition);
	else if (charaSelecter_->Get_2PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_2_2, m_2Pposition);
	else if (charaSelecter_->Get_2PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite((int)SpriteID::SelICO_2_3, m_2Pposition);

	if (sceneParameters_->Get_NextSceneID() == SceneID::GameFour)
	{
		if (charaSelecter_->Get_3PChara() == CharaID::None)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_3_D, m_3Pposition);
		else if (charaSelecter_->Get_3PChara() == CharaID::Chiya)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_3_0, m_3Pposition);
		else if (charaSelecter_->Get_3PChara() == CharaID::Rize)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_3_1, m_3Pposition);
		else if (charaSelecter_->Get_3PChara() == CharaID::Syaro)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_3_2, m_3Pposition);
		else if (charaSelecter_->Get_3PChara() == CharaID::Cocoa)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_3_3, m_3Pposition);

		if (charaSelecter_->Get_4PChara() == CharaID::None)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_4_D, m_4Pposition);
		else if (charaSelecter_->Get_4PChara() == CharaID::Chiya)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_4_0, m_4Pposition);
		else if (charaSelecter_->Get_4PChara() == CharaID::Rize)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_4_1, m_4Pposition);
		else if (charaSelecter_->Get_4PChara() == CharaID::Syaro)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_4_2, m_4Pposition);
		else if (charaSelecter_->Get_4PChara() == CharaID::Cocoa)
			Graphics2D::draw_sprite((int)SpriteID::SelICO_4_3, m_4Pposition);
	}
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

void CharaSelect::BaseSelectUpdate(float deltaTime)
{
	input1P_.update();
	input2P_.update();

	if (input1P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			Sound::play_se((int)SoundID_SE::Chiya_Select);
			charaSelecter_->Set_1PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			Sound::play_se((int)SoundID_SE::Rize_Select);
			charaSelecter_->Set_1PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionSyaro())
		{
			Sound::play_se((int)SoundID_SE::Syaro_Select);
			charaSelecter_->Set_1PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionCocoa())
		{
			Sound::play_se((int)SoundID_SE::Cocoa_Select);
			charaSelecter_->Set_1PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}
	if (input2P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			Sound::play_se((int)SoundID_SE::Chiya_Select);
			charaSelecter_->Set_2PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			Sound::play_se((int)SoundID_SE::Rize_Select);
			charaSelecter_->Set_2PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionSyaro())
		{
			Sound::play_se((int)SoundID_SE::Syaro_Select);
			charaSelecter_->Set_2PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionCocoa())
		{
			Sound::play_se((int)SoundID_SE::Cocoa_Select);
			charaSelecter_->Set_2PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}

	if (charaSelecter_->Get_1PChara() == CharaID::None)
	{
		if (input1P_.Stay(PAD_INPUT_UP))
			m_1Pposition.y -= deltaTime * m_icoSpeed;
		else if (input1P_.Stay(PAD_INPUT_DOWN))
			m_1Pposition.y += deltaTime * m_icoSpeed;
		if (input1P_.Stay(PAD_INPUT_LEFT))
			m_1Pposition.x -= deltaTime * m_icoSpeed;
		else if (input1P_.Stay(PAD_INPUT_RIGHT))
			m_1Pposition.x += deltaTime * m_icoSpeed;
	}

	if (charaSelecter_->Get_2PChara() == CharaID::None)
	{
		if (input2P_.Stay(PAD_INPUT_UP))
			m_2Pposition.y -= deltaTime * m_icoSpeed;
		else if (input2P_.Stay(PAD_INPUT_DOWN))
			m_2Pposition.y += deltaTime * m_icoSpeed;
		if (input2P_.Stay(PAD_INPUT_LEFT))
			m_2Pposition.x -= deltaTime * m_icoSpeed;
		else if (input2P_.Stay(PAD_INPUT_RIGHT))
			m_2Pposition.x += deltaTime * m_icoSpeed;
	}

	m_1Pposition = Vector2::Clamp(m_1Pposition, Vector2::Zero, Vector2{ 1180.0f,620.0f });
	m_2Pposition = Vector2::Clamp(m_2Pposition, Vector2::Zero, Vector2{ 1180.0f,620.0f });
}

void CharaSelect::DuelSelect(float deltaTime)
{
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
	input3P_.update();
	input4P_.update();

	if (FourSelected())
	{
		if (m_sceneEndTimer <= 0.0f)
		{
			m_isEnd = true;
			return;
		}
		m_sceneEndTimer -= deltaTime;
	}

	if (input3P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_3Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			Sound::play_se((int)SoundID_SE::Chiya_Select);
			charaSelecter_->Set_3PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_3Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			Sound::play_se((int)SoundID_SE::Rize_Select);
			charaSelecter_->Set_3PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_3Pposition) && !charaSelecter_->Get_SelectionSyaro())
		{
			Sound::play_se((int)SoundID_SE::Syaro_Select);
			charaSelecter_->Set_3PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_3Pposition) && !charaSelecter_->Get_SelectionCocoa())
		{
			Sound::play_se((int)SoundID_SE::Cocoa_Select);
			charaSelecter_->Set_3PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}
	if (input4P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_4Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			Sound::play_se((int)SoundID_SE::Chiya_Select);
			charaSelecter_->Set_4PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_4Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			Sound::play_se((int)SoundID_SE::Rize_Select);
			charaSelecter_->Set_4PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_4Pposition) && !charaSelecter_->Get_SelectionSyaro())
		{
			Sound::play_se((int)SoundID_SE::Syaro_Select);
			charaSelecter_->Set_4PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_4Pposition) && !charaSelecter_->Get_SelectionCocoa())
		{
			Sound::play_se((int)SoundID_SE::Cocoa_Select);
			charaSelecter_->Set_4PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}

	if (charaSelecter_->Get_3PChara() == CharaID::None)
	{
		if (input3P_.Stay(PAD_INPUT_UP))
			m_3Pposition.y -= deltaTime * m_icoSpeed;
		else if (input3P_.Stay(PAD_INPUT_DOWN))
			m_3Pposition.y += deltaTime * m_icoSpeed;
		if (input3P_.Stay(PAD_INPUT_LEFT))
			m_3Pposition.x -= deltaTime * m_icoSpeed;
		else if (input3P_.Stay(PAD_INPUT_RIGHT))
			m_3Pposition.x += deltaTime * m_icoSpeed;
	}

	if (charaSelecter_->Get_4PChara() == CharaID::None)
	{
		if (input4P_.Stay(PAD_INPUT_UP))
			m_4Pposition.y -= deltaTime * m_icoSpeed;
		else if (input4P_.Stay(PAD_INPUT_DOWN))
			m_4Pposition.y += deltaTime * m_icoSpeed;
		if (input4P_.Stay(PAD_INPUT_LEFT))
			m_4Pposition.x -= deltaTime * m_icoSpeed;
		else if (input4P_.Stay(PAD_INPUT_RIGHT))
			m_4Pposition.x += deltaTime * m_icoSpeed;
	}

	m_3Pposition = Vector2::Clamp(m_3Pposition, Vector2::Zero, Vector2{ 1180.0f,620.0f });
	m_4Pposition = Vector2::Clamp(m_4Pposition, Vector2::Zero, Vector2{ 1180.0f,620.0f });
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

bool CharaSelect::ChiyaSelectArea(Vector2 l_icoPosition)const
{
	if (l_icoPosition.x >= 0.0f&&l_icoPosition.x <= 275.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::RizeSelectArea(Vector2 l_icoPosition)const
{
	if (l_icoPosition.x >= 300.0f&&l_icoPosition.x <= 575.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::SyaroSelectArea(Vector2 l_icoPosition)const
{
	if (l_icoPosition.x >= 600.0f&&l_icoPosition.x <= 875.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::CocoaSelectArea(Vector2 l_icoPosition)const
{
	if (l_icoPosition.x >= 900.0f&&l_icoPosition.x <= 1175.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}
