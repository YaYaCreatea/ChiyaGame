#include "Duel.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"

#include "../../Camera/DuelCamera/DuelCamera.h"
#include "../../Character/Player/Player.h"
#include "../../Character/Player/_Chiya/Chiya.h"
#include "../../Character/Player/_Rize/Rize.h"
#include "../../Character/Player/_Syaro/Syaro.h"
#include "../../Character/Player/_Cocoa/Cocoa.h"
#include "../../Character/Enemy/Enemy.h"

#include "../../assetsID/AssetsID.h"
#include "../SceneID.h"

void Duel::start()
{
	Graphics3D::initialize();
	Graphics2D::initialize();
	SkeletalMesh::initialize();
	CollisionMesh::initialize();
	SkyBox::initialize();
	Billboard::initialize();

	//3Dモデルの読み込み
	SkeletalMesh::load((int)ModelCharaID::Chiya, "asset/Chiya2/千夜.mv1");
	SkeletalMesh::load((int)ModelCharaID::Rize, "asset/Rize/リゼ.mv1");
	SkeletalMesh::load((int)ModelCharaID::Syaro, "asset/Syaro/シャロ.mv1");
	SkeletalMesh::load((int)ModelCharaID::Cocoa, "asset/Cocoa/ココア.mv1");
	//StaticMesh::load(0, "asset/w_magun01.mv1");
	//StaticMesh::load(0, "asset/Sword.mv1");
	StaticMesh::load((int)ModelWeaponID::Spear, "asset/weapon/Spear.mv1");
	StaticMesh::load((int)ModelWeaponID::Gun, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load((int)ModelWeaponID::Katana, "asset/weapon/Katana/Katana.mv1");

	//UIリソース読み込み	
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya, "asset/2Dsprite/GamePlay/BackFrame_Chiya.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize, "asset/2Dsprite/GamePlay/BackFrame_Rize.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro, "asset/2Dsprite/GamePlay/BackFrame_Syaro.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa, "asset/2Dsprite/GamePlay/BackFrame_Cocoa.png");
	Graphics2D::load_sprite((int)SpriteID::HpGauge, "asset/2Dsprite/PlayerUI/HpGauge2.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya_4, "asset/2Dsprite/GamePlay/BackFrame_Chiya_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize_4, "asset/2Dsprite/GamePlay/BackFrame_Rize_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro_4, "asset/2Dsprite/GamePlay/BackFrame_Syaro_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa_4, "asset/2Dsprite/GamePlay/BackFrame_Cocoa_4.png");

	//ステージモデルの読み込み
	CollisionMesh::load(0, "asset/Stage/StageTest/Stage4.mv1");
	//スカイボックスの読み込み
	SkyBox::load(0, "asset/skybox/Dome_SS601.mv1");
	//ビルボードの読み込み
	Billboard::load(0, "asset/Particle02.png");
	Billboard::load(1, "asset/2Dsprite/PlayerUI/HpGauge.png");

	world_.initialize();

	world_.add_camera(new_actor<DuelCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 180.0f, "Chiya"),
		new_actor<DuelCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, "Rize"));
	//world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 180.0f, "Chiya"),
	//	new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, "Syaro"));
	//world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 180.0f, "Chiya"),
	//	new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, "Cocoa"));

	world_.add_actor(ActorGroup::Chiya, new_actor<Chiya>(world_, "Chiya", Vector3{ 0.0f,0.0f,-540.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f), (int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana));
	world_.add_actor(ActorGroup::Rize, new_actor<Rize>(world_, "Rize", Vector3{ 0.0f,0.0f,540.0f }, Matrix::Identity, (int)ModelCharaID::Rize, (int)ModelWeaponID::Spear));
	//world_.add_actor(ActorGroup::Syaro, new_actor<Syaro>(world_, "Syaro", Vector3{ -20.0f,0.0f,0.0f },Matrix::Identity, (int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun));
	//world_.add_actor(ActorGroup::Cocoa, new_actor<Cocoa>(world_, "Cocoa", Vector3{ 20.0f,0.0f,20.0f },Matrix::Identity, (int)ModelCharaID::Cocoa));
}

void Duel::update(float deltaTime)
{
	world_.update(deltaTime);
}

void Duel::draw() const
{
	//画面のクリア
	Graphics3D::clear();
	//スカイボックスの描画
	SkyBox::bind(0);

	//ステージの描画
	CollisionMesh::bind(0);

	world_.draw();
	world_.draw2();

	frameCamera_.drawDuel();
}

bool Duel::is_end() const
{
	return m_isEnd;
}

SceneID Duel::next() const
{
	return SceneID::Title;
}

void Duel::end()
{
	world_.clear();

	//モデルデータの削除
	SkeletalMesh::erase(0);
	SkeletalMesh::erase(1);
	SkeletalMesh::erase(2);
	SkeletalMesh::erase(3);
	StaticMesh::erase(0);
	StaticMesh::erase(1);
	StaticMesh::erase(2);
	CollisionMesh::erase(0);
	SkyBox::erase(0);
	Billboard::erase(0);
	Billboard::erase(1);

	Billboard::finalize();
	SkeletalMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Graphics3D::finalize();
	Graphics2D::finalize();
}
