#include "Duel.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"
#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"

#include "../../Camera/DuelCamera/DuelCamera.h"
#include "../../Character/Player/Player.h"
#include "../../Character/Player/_Chiya/Chiya.h"
#include "../../Character/Player/_Rize/Rize.h"
#include "../../Character/Player/_Syaro/Syaro.h"
#include "../../Character/Player/_Cocoa/Cocoa.h"
#include "../../Character/Enemy/Enemy.h"


Duel::Duel(PlayLoad & l_load)
{
	load_ = &l_load;
}

void Duel::start()
{
	m_isEnd = false;

	Graphics3D::initialize();

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

	EndCheck();
}

void Duel::draw() const
{
	//画面のクリア
	Graphics3D::clear();

	SkyBox::bind(0);
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
	return SceneID::StartUp;
}

void Duel::end()
{
	world_.clear();

	//ゲームモードのリソースアンロード
	load_->UnLoad();

	Graphics3D::finalize();
}

void Duel::EndCheck()
{
	if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
		|| world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown())
	{
		m_isEnd = true;
	}
	//if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
	//	|| world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown())
	//{
	//	m_isEnd = true;
	//}
	//if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
	//	|| world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
	//{
	//	m_isEnd = true;
	//}
}
