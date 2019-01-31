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

//•`‰æ(Duel—p)
void FrameCamera::drawDuel() const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Chiya, Vector2{ 0.0f,0.0f });
	Graphics2D::draw_sprite_Frame((int)SpriteID::Frame_Rize, Vector2{ 640.0f,0.0f });
	DrawFormatStringF(0.0f, 0.0f, 1, "(%d)", GetJoypadNum());
}

//•`‰æ(Four—p)
void FrameCamera::drawFour() const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Chiya_4, Vector2{ 0.0f,0.0f });
	Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Rize_4, Vector2{ 640.0f,0.0f });
	Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Syaro_4, Vector2{ 0.0f,360.0f });
	Graphics2D::draw_sprite_Frame4((int)SpriteID::Frame_Cocoa_4, Vector2{ 640.0f,360.0f });
	DrawFormatStringF(0.0f, 0.0f, 1, "(%d)", GetJoypadNum());
}
