#include "GameFrame.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../EventMessage.h"

#include "../Camera/TpsCamera.h"
#include "../Character/Player/Player.h"
#include "../Character/Player/_Chiya/Chiya.h"
#include "../Character/Player/_Rize/Rize.h"
#include "../Character/Player/_Syaro/Syaro.h"
#include "../Character/Player/_Cocoa/Cocoa.h"
#include "../Character/Enemy/Enemy.h"

GameFrame::GameFrame()
	:Game{ 1280,720,false }
{
}

void GameFrame::start()
{
	Graphics3D::initialize();
	SkeletalMesh::initialize();
	CollisionMesh::initialize();
	SkyBox::initialize();
	Billboard::initialize();

	//3Dモデルの読み込み
	SkeletalMesh::load(0, "asset/Chiya2/千夜.mv1");
	SkeletalMesh::load(1, "asset/Rize/リゼ.mv1");
	SkeletalMesh::load(2, "asset/Syaro/シャロ.mv1");
	SkeletalMesh::load(3, "asset/Cocoa/ココア.mv1");
	//StaticMesh::load(0, "asset/w_magun01.mv1");
	//StaticMesh::load(0, "asset/Sword.mv1");
	StaticMesh::load(0, "asset/weapon/Spear.mv1");
	StaticMesh::load(1, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load(2, "asset/weapon/Katana/Katana.mv1");

	//UIリソース読み込み
	Graphics2D::load_sprite(0, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Graphics2D::load_sprite(1, "asset/2Dsprite/GamePlay/BackFrame.png");
	Graphics2D::load_sprite(2, "asset/2Dsprite/GamePlay/BackFrame_Chiya.png");
	Graphics2D::load_sprite(3, "asset/2Dsprite/GamePlay/BackFrame_Rize.png");
	Graphics2D::load_sprite(4, "asset/2Dsprite/GamePlay/BackFrame_Syaro.png");

	//ステージモデルの読み込み
	CollisionMesh::load(0, "asset/Stage/test3.mv1");
	//スカイボックスの読み込み
	SkyBox::load(0, "asset/skybox/skydome.mv1");
	//ビルボードの読み込み
	Billboard::load(0, "asset/Particle02.png");

	world_.initialize();

	//world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Chiya"),
	//	new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Rize"));
	//world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Chiya"),
	//	new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Syaro"));
	world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Chiya"),
		new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Cocoa"));

	world_.add_actor(ActorGroup::Player, new_actor<Chiya>(world_, "Chiya", Vector3::Zero, 0, 2));
	//world_.add_actor(ActorGroup::Enemy, new_actor<Rize>(world_, "Rize", Vector3{ 20.0f,0.0f,0.0f }, 1, 0));
	//world_.add_actor(ActorGroup::Enemy, new_actor<Syaro>(world_, "Syaro", Vector3{ 20.0f,0.0f,0.0f }, 2, 1));
	world_.add_actor(ActorGroup::Enemy, new_actor<Cocoa>(world_, "Cocoa", Vector3{ 20.0f,0.0f,0.0f }, 3));

	//ChangeLightTypeDir(VGet(1.0f, -1.0f, 1.0f));
}

void GameFrame::update(float deltaTime)
{
	world_.update(deltaTime);
}

void GameFrame::draw()
{
	//画面のクリア
	Graphics3D::clear();
	//スカイボックスの描画
	SkyBox::bind(0);

	//ステージの描画
	CollisionMesh::bind(0);

	world_.draw();
	world_.draw2();

	//ビルボードの描画
	/*Graphics3D::blend_model(BlendMode::Add);
	Billboard::bind(0);
	Billboard::draw({ 0.0f,30.0f,0.0f }, 10.0f);
	Graphics3D::blend_model(BlendMode::None);*/
}

void GameFrame::end()
{
	world_.clear();

	//モデルデータの削除
	SkeletalMesh::erase(0);
	StaticMesh::erase(0);

	Billboard::finalize();
	SkeletalMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Graphics3D::finalize();
	Graphics2D::finalize();
}
