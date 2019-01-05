#include "GameFrame.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../EventMessage.h"

#include "../Camera/TpsCamera.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"

GameFrame::GameFrame()
	:Game{ 1024,768,false }
{
}

void GameFrame::start()
{
	Graphics3D::initialize();
	SkeletalMesh::initialize();
	CollisionMesh::initialize();
	SkyBox::initialize();
	Billboard::initialize();
	GamePad::initialize();

	//3Dモデルの読み込み
	SkeletalMesh::load(0, "asset/Chiya2/千夜.mv1");
	//StaticMesh::load(0, "asset/w_magun01.mv1");
	//StaticMesh::load(0, "asset/Sword.mv1");
	StaticMesh::load(0, "asset/weapon/Spear.mv1");
	StaticMesh::load(1, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load(2, "asset/weapon/Katana/Katana.mv1");
	//ステージモデルの読み込み
	//CollisionMesh::load(0, "asset/castle/SampleStage_Castle.mv1");
	CollisionMesh::load(0, "asset/Stage/test3.mv1");
	//スカイボックスの読み込み
	SkyBox::load(0, "asset/skybox/skydome.mv1");
	//ビルボードの読み込み
	Billboard::load(0, "asset/Particle02.png");

	world_.initialize();

	world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }));

	world_.add_actor(ActorGroup::Player, new_actor<Player>(world_, Vector3::Zero, 0, 2));
	world_.add_actor(ActorGroup::Enemy, new_actor<Enemy>(world_, Vector3{ 0.0f,0.0f,-30.0f }, 0));

	//ChangeLightTypeDir(VGet(1.0f, -1.0f, 1.0f));
}

void GameFrame::update(float deltaTime)
{
	GamePad::update();
	world_.update(deltaTime);
}

void GameFrame::draw()
{
	//画面のクリア
	Graphics3D::clear();

	//スカイボックスの描画
	SkyBox::bind(0);
	SkyBox::draw();

	//ステージの描画
	CollisionMesh::bind(0);
	CollisionMesh::draw();

	world_.draw();

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

	GamePad::finalize();
	Billboard::finalize();
	SkeletalMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Graphics3D::finalize();
}
