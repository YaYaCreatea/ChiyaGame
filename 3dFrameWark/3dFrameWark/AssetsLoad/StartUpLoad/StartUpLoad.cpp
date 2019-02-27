#include "StartUpLoad.h"

#include "../../assetsID/AssetsID.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../Sound/Sound.h"

StartUpLoad::StartUpLoad()
{
}

StartUpLoad::~StartUpLoad()
{
}

void StartUpLoad::Load()
{
	m_loadNum = 0;

	Graphics2D::initialize();
	CollisionMesh::initialize();
	SkyBox::initialize();

	SetUseASyncLoadFlag(TRUE);	

	//ロード,タイトル
	Graphics2D::load_sprite((int)SpriteID::LoadGauge, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Graphics2D::load_sprite((int)SpriteID::TitleBack, "asset/2Dsprite/Title/TitleBack.png");

	//モードセレクト
	Graphics2D::load_sprite((int)SpriteID::Mode1on1_Act, "asset/2Dsprite/ModeSelect/Mode1on1_Act.png");
	Graphics2D::load_sprite((int)SpriteID::Mode1on1_Dact, "asset/2Dsprite/ModeSelect/Mode1on1_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::ModeFour_Act, "asset/2Dsprite/ModeSelect/ModeFour_Act.png");
	Graphics2D::load_sprite((int)SpriteID::ModeFour_Dact, "asset/2Dsprite/ModeSelect/ModeFour_Dact.png");

	//キャラクターセレクト
	Graphics2D::load_sprite((int)SpriteID::CharaSelectBack, "asset/2Dsprite/CharaSelect/CharaSelectBack.png");
	Graphics2D::load_sprite((int)SpriteID::CharaSelectChiya, "asset/2Dsprite/CharaSelect/CharaChiya.png");
	Graphics2D::load_sprite((int)SpriteID::CharaSelectRize, "asset/2Dsprite/CharaSelect/CharaRize.png");
	Graphics2D::load_sprite((int)SpriteID::CharaSelectSyaro, "asset/2Dsprite/CharaSelect/CharaSyaro.png");
	Graphics2D::load_sprite((int)SpriteID::CharaSelectCocoa, "asset/2Dsprite/CharaSelect/CharaCocoa.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_1_D, "asset/2Dsprite/CharaSelect/ICO/1PICO_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_1_0, "asset/2Dsprite/CharaSelect/ICO/1PICO_act0.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_1_1, "asset/2Dsprite/CharaSelect/ICO/1PICO_act1.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_1_2, "asset/2Dsprite/CharaSelect/ICO/1PICO_act2.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_1_3, "asset/2Dsprite/CharaSelect/ICO/1PICO_act3.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_2_D, "asset/2Dsprite/CharaSelect/ICO/2PICO_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_2_0, "asset/2Dsprite/CharaSelect/ICO/2PICO_act0.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_2_1, "asset/2Dsprite/CharaSelect/ICO/2PICO_act1.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_2_2, "asset/2Dsprite/CharaSelect/ICO/2PICO_act2.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_2_3, "asset/2Dsprite/CharaSelect/ICO/2PICO_act3.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_3_D, "asset/2Dsprite/CharaSelect/ICO/3PICO_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_3_0, "asset/2Dsprite/CharaSelect/ICO/3PICO_act0.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_3_1, "asset/2Dsprite/CharaSelect/ICO/3PICO_act1.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_3_2, "asset/2Dsprite/CharaSelect/ICO/3PICO_act2.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_3_3, "asset/2Dsprite/CharaSelect/ICO/3PICO_act3.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_4_D, "asset/2Dsprite/CharaSelect/ICO/4PICO_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_4_0, "asset/2Dsprite/CharaSelect/ICO/4PICO_act0.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_4_1, "asset/2Dsprite/CharaSelect/ICO/4PICO_act1.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_4_2, "asset/2Dsprite/CharaSelect/ICO/4PICO_act2.png");
	Graphics2D::load_sprite((int)SpriteID::SelICO_4_3, "asset/2Dsprite/CharaSelect/ICO/4PICO_act3.png");

	//BGM,SE
	Sound::load_bgm((int)SoundID_BGM::ModeSelect, "asset/Sound/BGM/spadenoheitai.mp3");
	Sound::load_bgm((int)SoundID_BGM::CharaSelect, "asset/Sound/BGM/chess.mp3");
	
	Sound::load_se((int)SoundID_SE::SystemSelect, "asset/Sound/SE/System/select.wav");
	Sound::load_se((int)SoundID_SE::Chiya_Select, "asset/Sound/SE/Chiya/healer-guard2.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Select, "asset/Sound/SE/Rize/swordwoman-start2.mp3");
	Sound::load_se((int)SoundID_SE::Syaro_Select, "asset/Sound/SE/Syaro/princess-greeting1.mp3");
	Sound::load_se((int)SoundID_SE::Cocoa_Select, "asset/Sound/SE/Cocoa/witch-start2.mp3");

	//モードセレクトモデル
	CollisionMesh::load(0, "asset/Stage/StageTest/Stage4.mv1");
	SkyBox::load(0, "asset/skybox/Dome_SS601.mv1");

	SetUseASyncLoadFlag(FALSE);

	m_loadNum = GetASyncLoadNum();
}

void StartUpLoad::UnLoad()
{
	Sound::finalize();
	Graphics2D::finalize();
}

int StartUpLoad::get_loadNum() const
{
	return m_loadNum;
}
