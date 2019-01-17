#include "GameFrame.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../EventMessage.h"

#include "../Camera/TpsCamera.h"
#include "../Character/Player/Player.h"
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
	GamePad::initialize();

	//3D���f���̓ǂݍ���
	SkeletalMesh::load(0, "asset/Chiya2/���.mv1");
	//StaticMesh::load(0, "asset/w_magun01.mv1");
	//StaticMesh::load(0, "asset/Sword.mv1");
	StaticMesh::load(0, "asset/weapon/Spear.mv1");
	StaticMesh::load(1, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load(2, "asset/weapon/Katana/Katana.mv1");
	//�X�e�[�W���f���̓ǂݍ���
	//CollisionMesh::load(0, "asset/castle/SampleStage_Castle.mv1");
	CollisionMesh::load(0, "asset/Stage/test3.mv1");
	//�X�J�C�{�b�N�X�̓ǂݍ���
	SkyBox::load(0, "asset/skybox/skydome.mv1");
	//�r���{�[�h�̓ǂݍ���
	Billboard::load(0, "asset/Particle02.png");

	world_.initialize();

	world_.add_camera(new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f },"Player0"), 
		new_actor<TpsCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, "Player1"));

	world_.add_actor(ActorGroup::Player, new_actor<Player>(world_, "Player0", Vector3::Zero, 0, 2));
	world_.add_actor(ActorGroup::Player, new_actor<Player>(world_, "Player1", Vector3{ 0.0f,0.0f,-20.0f }, 0, 2));
	//world_.add_actor(ActorGroup::Enemy, new_actor<Enemy>(world_, Vector3{ 0.0f,0.0f,-30.0f }, 0));

	//ChangeLightTypeDir(VGet(1.0f, -1.0f, 1.0f));
}

void GameFrame::update(float deltaTime)
{
	world_.update(deltaTime);
}

void GameFrame::draw()
{
	//��ʂ̃N���A
	Graphics3D::clear();

	//�X�J�C�{�b�N�X�̕`��
	SkyBox::bind(0);
	SkyBox::draw();

	//�X�e�[�W�̕`��
	CollisionMesh::bind(0);
	CollisionMesh::draw();

	world_.draw();

	SkyBox::draw();
	CollisionMesh::draw();
	world_.draw2();

	//�r���{�[�h�̕`��
	/*Graphics3D::blend_model(BlendMode::Add);
	Billboard::bind(0);
	Billboard::draw({ 0.0f,30.0f,0.0f }, 10.0f);
	Graphics3D::blend_model(BlendMode::None);*/
}

void GameFrame::end()
{
	world_.clear();

	//���f���f�[�^�̍폜
	SkeletalMesh::erase(0);
	StaticMesh::erase(0);

	GamePad::finalize();
	Billboard::finalize();
	SkeletalMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Graphics3D::finalize();
}
