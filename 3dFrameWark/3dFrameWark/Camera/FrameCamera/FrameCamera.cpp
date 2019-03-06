#include "FrameCamera.h"

#include "../../Graphics2D/Graphics2D.h"
#include "../../Graphics3D/Graphics3D.h"
#include "../../Utility/Vector2/Vector2.h"

#include "../../assetsID/AssetsID.h"

FrameCamera::FrameCamera()
{	
}

FrameCamera::~FrameCamera()
{
}

void FrameCamera::initialize(CharacterSelecter& l_selecter)
{
	charaSelecter_ = &l_selecter;
}

//•`‰æ(Duel—p)
void FrameCamera::drawDuel() const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	if (charaSelecter_->Get_1PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Chiya, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Rize, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Syaro, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Cocoa, Vector2::Zero);

	if (charaSelecter_->Get_2PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Chiya, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Rize, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Syaro, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Cocoa, Vector2{ 640.0f,0.0f });
}

//•`‰æ(Four—p)
void FrameCamera::drawFour() const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	if (charaSelecter_->Get_1PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Chiya_4, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Rize_4, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Syaro_4, Vector2::Zero);
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Cocoa_4, Vector2::Zero);

	if (charaSelecter_->Get_2PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Chiya_4, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Rize_4, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Syaro_4, Vector2{ 640.0f,0.0f });
	else if (charaSelecter_->Get_2PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Cocoa_4, Vector2{ 640.0f,0.0f });

	if (charaSelecter_->Get_3PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Chiya_4, Vector2{ 0.0f,360.0f });
	else if (charaSelecter_->Get_3PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Rize_4, Vector2{ 0.0f,360.0f });
	else if (charaSelecter_->Get_3PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Syaro_4, Vector2{ 0.0f,360.0f });
	else if (charaSelecter_->Get_3PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Cocoa_4, Vector2{ 0.0f,360.0f });

	if (charaSelecter_->Get_4PChara() == CharaID::Chiya)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Chiya_4, Vector2{ 640.0f,360.0f });
	else if (charaSelecter_->Get_4PChara() == CharaID::Rize)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Rize_4, Vector2{ 640.0f,360.0f });
	else if (charaSelecter_->Get_4PChara() == CharaID::Syaro)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Syaro_4, Vector2{ 640.0f,360.0f });
	else if (charaSelecter_->Get_4PChara() == CharaID::Cocoa)
		Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Cocoa_4, Vector2{ 640.0f,360.0f });
}
