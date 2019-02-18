#include "CharaSelect.h"

#include "../../assetsID/AssetsID.h"

#include "../../Graphics2D/Graphics2D.h"

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

	charaSelecter_->initialize();

	m_1Pposition = Vector2::Zero;
	m_2Pposition = Vector2{ 1180.0f,0.0f };
	m_icoSpeed = 10.0f;
	m_sceneEndTimer = 120.0f;
}

void CharaSelect::update(float deltaTime)
{
	input1P_.update();
	input2P_.update();

	if (input1P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			charaSelecter_->Set_1PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_1Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			charaSelecter_->Set_1PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_1Pposition))
		{
			charaSelecter_->Set_1PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_1Pposition))
		{
			charaSelecter_->Set_1PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}
	if (input2P_.Trigger(PAD_INPUT_1))
	{
		if (ChiyaSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionChiya())
		{
			charaSelecter_->Set_2PChara(CharaID::Chiya);
			charaSelecter_->SelectionChiya();
		}
		else if (RizeSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionRize())
		{
			charaSelecter_->Set_2PChara(CharaID::Rize);
			charaSelecter_->SelectionRize();
		}
		else if (SyaroSelectArea(m_2Pposition)&& !charaSelecter_->Get_SelectionSyaro())
		{
			charaSelecter_->Set_2PChara(CharaID::Syaro);
			charaSelecter_->SelectionSyaro();
		}
		else if (CocoaSelectArea(m_2Pposition) && !charaSelecter_->Get_SelectionCocoa())
		{
			charaSelecter_->Set_2PChara(CharaID::Cocoa);
			charaSelecter_->SelectionCocoa();
		}
	}

	if (charaSelecter_->Get_1PChara() != CharaID::None
		&&charaSelecter_->Get_2PChara() != CharaID::None)
	{
		if (m_sceneEndTimer <= 0.0f)
		{
			m_isEnd = true;
			return;
		}
		m_sceneEndTimer -= deltaTime;
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

bool CharaSelect::ChiyaSelectArea(Vector2 l_icoPosition)
{
	if (l_icoPosition.x >= 0.0f&&l_icoPosition.x <= 275.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::RizeSelectArea(Vector2 l_icoPosition)
{
	if (l_icoPosition.x >= 300.0f&&l_icoPosition.x <= 575.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::SyaroSelectArea(Vector2 l_icoPosition)
{
	if (l_icoPosition.x >= 600.0f&&l_icoPosition.x <= 875.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

bool CharaSelect::CocoaSelectArea(Vector2 l_icoPosition)
{
	if (l_icoPosition.x >= 900.0f&&l_icoPosition.x <= 1175.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}
