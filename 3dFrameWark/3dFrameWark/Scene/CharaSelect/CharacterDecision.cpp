#include "CharacterDecision.h"
#include <DxLib.h>

#include "../../assetsID/AssetsID.h"
#include "../../Sound/Sound.h"
#include "../../Graphics2D/Graphics2D.h"

CharacterDecision::CharacterDecision(CharacterSelecter & l_selecter)
{
	charaSelecter_ = &l_selecter;
}

// キャラクターセレクト制御初期化
void CharacterDecision::Initialize()
{
	// インプットの初期化
	input1P_.initialize(DX_INPUT_PAD1);
	input2P_.initialize(DX_INPUT_PAD2);
	input3P_.initialize(DX_INPUT_PAD3);
	input4P_.initialize(DX_INPUT_PAD4);

	// アイコン位置の初期化
	m_1Pposition = Vector2::Zero;
	m_2Pposition = Vector2{ 1180.0f,0.0f };
	m_3Pposition = Vector2{ 0.0f,620.0f };
	m_4Pposition = Vector2{ 1180.0f,620.0f };

	m_icoSpeed = 10.0f;
}

// 1on1時のキャラクターセレクト制御
void CharacterDecision::Decision_Duel(float deltaTime)
{
	// インプットの更新(1P,2P)
	input1P_.update();
	input2P_.update();

	// 1Pのセレクト判定
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
	// 2Pのセレクト判定
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

	// 1Pアイコン移動制御
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

	// 2Pアイコン移動制御
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

// 4人対戦時のキャラクターセレクト制御
void CharacterDecision::Decision_Four(float deltaTime)
{
	// 1P,2Pのキャラクターセレクト制御
	Decision_Duel(deltaTime);

	// インプットの更新(3P,4P)
	input3P_.update();
	input4P_.update();

	// 3Pのセレクト判定
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

	// 4Pのセレクト判定
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

	// 3Pアイコン移動制御
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

	// 4Pアイコン移動制御
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

// 1on1時のキャラクターセレクトアイコンの描画
void CharacterDecision::DrawDecisionICO_Duel() const
{
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

// 4人対戦時のキャラクターセレクトアイコンの描画
void CharacterDecision::DrawDecisionICO_Four() const
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

// 千夜のセレクト範囲
bool CharacterDecision::ChiyaSelectArea(Vector2 l_icoPosition) const
{
	if (l_icoPosition.x >= 0.0f&&l_icoPosition.x <= 275.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

// リゼのセレクト範囲
bool CharacterDecision::RizeSelectArea(Vector2 l_icoPosition) const
{
	if (l_icoPosition.x >= 300.0f&&l_icoPosition.x <= 575.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

// シャロのセレクト範囲
bool CharacterDecision::SyaroSelectArea(Vector2 l_icoPosition) const
{
	if (l_icoPosition.x >= 600.0f&&l_icoPosition.x <= 875.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}

// ココアのセレクト範囲
bool CharacterDecision::CocoaSelectArea(Vector2 l_icoPosition) const
{
	if (l_icoPosition.x >= 900.0f&&l_icoPosition.x <= 1175.0f
		&&l_icoPosition.y >= 100.0f&&l_icoPosition.y <= 584.0f)
		return true;

	return false;
}
