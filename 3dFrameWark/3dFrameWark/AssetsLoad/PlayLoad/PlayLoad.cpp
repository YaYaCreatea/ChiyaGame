#include "PlayLoad.h"

#include "../../assetsID/AssetsID.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../SkeletalMesh/SkeletalMesh.h"
#include "../../StaticMesh/StaticMesh.h"
#include "../../Billboard/Billboard.h"
#include "../../Effect/Effect.h"
#include "../../Sound/Sound.h"


PlayLoad::PlayLoad()
{

}

PlayLoad::~PlayLoad()
{
}

void PlayLoad::Load()
{
	m_loadNum = 0;

	SkeletalMesh::initialize();
	StaticMesh::initialize();
	Graphics2D::initialize();
	Billboard::initialize();
	//Effect::initialize();

	SetUseASyncLoadFlag(TRUE);

	//3Dモデルの読み込み
	SkeletalMesh::load((int)ModelCharaID::Chiya, "asset/Chiya2/千夜.mv1");
	SkeletalMesh::load((int)ModelCharaID::Rize, "asset/Rize/リゼ.mv1");
	SkeletalMesh::load((int)ModelCharaID::Syaro, "asset/Syaro/シャロ.mv1");
	SkeletalMesh::load((int)ModelCharaID::Cocoa, "asset/Cocoa/ココア.mv1");
	SkeletalMesh::load((int)ModelCharaID::Boss, "asset/Boss/怪獣.mv1");

	//スタティックメッシュ読み込み
	StaticMesh::load((int)ModelWeaponID::Spear, "asset/weapon/Spear.mv1");
	StaticMesh::load((int)ModelWeaponID::Gun, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load((int)ModelWeaponID::Katana, "asset/weapon/Katana/Katana.mv1");

	//UIリソース読み込み
	Graphics2D::load_sprite((int)SpriteID::LoadGauge, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya, "asset/2Dsprite/GamePlay/BackFrame_Chiya.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize, "asset/2Dsprite/GamePlay/BackFrame_Rize.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro, "asset/2Dsprite/GamePlay/BackFrame_Syaro.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa, "asset/2Dsprite/GamePlay/BackFrame_Cocoa.png");
	Graphics2D::load_sprite((int)SpriteID::HpGauge, "asset/2Dsprite/PlayerUI/HpGauge2.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya_4, "asset/2Dsprite/GamePlay/BackFrame_Chiya_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize_4, "asset/2Dsprite/GamePlay/BackFrame_Rize_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro_4, "asset/2Dsprite/GamePlay/BackFrame_Syaro_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa_4, "asset/2Dsprite/GamePlay/BackFrame_Cocoa_4.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOff, "asset/2Dsprite/GamePlay/LockOnArea.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOn, "asset/2Dsprite/GamePlay/LockOnAreaOn.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOff_4, "asset/2Dsprite/GamePlay/LockOnArea_4.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOn_4, "asset/2Dsprite/GamePlay/LockOnAreaOn_4.png");
	Graphics2D::load_sprite((int)SpriteID::ResultBackChiya, "asset/2Dsprite/Result/WinnerChiya.png");
	Graphics2D::load_sprite((int)SpriteID::ResultBackRize, "asset/2Dsprite/Result/WinnerRize.png");
	Graphics2D::load_sprite((int)SpriteID::ResultBackSyaro, "asset/2Dsprite/Result/WinnerSyaro.png");
	Graphics2D::load_sprite((int)SpriteID::ResultBackCocoa, "asset/2Dsprite/Result/WinnerCocoa.png");

	//ビルボードの読み込み
	Billboard::load((int)BillBoardID::Hit, "asset/BillBoard/Hit.png");
	Billboard::load((int)BillBoardID::GunShot, "asset/BillBoard/GunEff.png");
	Billboard::load((int)BillBoardID::MagicShot, "asset/BillBoard/Particle02.png");

	//BGM
	Sound::load_bgm((int)SoundID_BGM::GameBGM, "asset/Sound/BGM/ryunomai.mp3");
	Sound::load_bgm((int)SoundID_BGM::Result, "asset/Sound/BGM/bacteria.mp3");

	//SE
	Sound::load_se((int)SoundID_SE::Chiya_Attack1, "asset/Sound/SE/Chiya/healer-attack1.mp3");
	Sound::load_se((int)SoundID_SE::Chiya_Attack2, "asset/Sound/SE/Chiya/healer-attack2.mp3");
	Sound::load_se((int)SoundID_SE::Chiya_Damage, "asset/Sound/SE/Chiya/healer-damage2.mp3");
	Sound::load_se((int)SoundID_SE::Chiya_Down, "asset/Sound/SE/Chiya/healer-death1.mp3");
	Sound::load_se((int)SoundID_SE::Chiya_Win, "asset/Sound/SE/Chiya/healer-win1.mp3");

	Sound::load_se((int)SoundID_SE::Rize_Attack1, "asset/Sound/SE/Rize/swordwoman-attack1.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Attack2, "asset/Sound/SE/Rize/swordwoman-attack3.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Attack3, "asset/Sound/SE/Rize/swordwoman-special1.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Attack4, "asset/Sound/SE/Rize/swordwoman-special2.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Damage, "asset/Sound/SE/Rize/swordwoman-damage2.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Down, "asset/Sound/SE/Rize/swordwoman-lose1.mp3");
	Sound::load_se((int)SoundID_SE::Rize_Win, "asset/Sound/SE/Rize/swordwoman-start2.mp3");

	Sound::load_se((int)SoundID_SE::Syaro_Attack1, "asset/Sound/SE/Syaro/princess-attack1.mp3");
	Sound::load_se((int)SoundID_SE::Syaro_Attack2, "asset/Sound/SE/Syaro/princess-attack3.mp3");
	Sound::load_se((int)SoundID_SE::Syaro_Damage, "asset/Sound/SE/Syaro/princess-damage2.mp3");
	Sound::load_se((int)SoundID_SE::Syaro_Down, "asset/Sound/SE/Syaro/princess-death1.mp3");
	Sound::load_se((int)SoundID_SE::Syaro_Win, "asset/Sound/SE/Syaro/princess-win1.mp3");

	Sound::load_se((int)SoundID_SE::Cocoa_Attack1, "asset/Sound/SE/Cocoa/witch-attack1.mp3");
	Sound::load_se((int)SoundID_SE::Cocoa_Attack2, "asset/Sound/SE/Cocoa/witch-attack3.mp3");
	Sound::load_se((int)SoundID_SE::Cocoa_Damage, "asset/Sound/SE/Cocoa/witch-damage2.mp3");
	Sound::load_se((int)SoundID_SE::Cocoa_Down, "asset/Sound/SE/Cocoa/witch-lose1.mp3");
	Sound::load_se((int)SoundID_SE::Cocoa_Win, "asset/Sound/SE/Cocoa/witch-attack2.mp3");

	Sound::load_se((int)SoundID_SE::Dash, "asset/Sound/SE/Attack/Dash.mp3");
	Sound::load_se((int)SoundID_SE::GunShot, "asset/Sound/SE/Attack/Gun.mp3");
	Sound::load_se((int)SoundID_SE::KatanaSlash, "asset/Sound/SE/Attack/Katana.mp3");

	SetUseASyncLoadFlag(FALSE);

	m_loadNum = GetASyncLoadNum();
}

void PlayLoad::UnLoad()
{
	SkeletalMesh::finalize();
	StaticMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Billboard::finalize();
	Effect::finalize();
	Sound::finalize();
	Graphics2D::finalize();
}

int PlayLoad::get_loadNum() const
{
	return m_loadNum;
}
