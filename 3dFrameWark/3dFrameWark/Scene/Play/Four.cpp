#include "Four.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"
#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"

#include "../../Camera/FourCamera/FourCamera.h"
#include "../../Character/Player/Player.h"
#include "../../Character/Player/_Chiya/Chiya.h"
#include "../../Character/Player/_Rize/Rize.h"
#include "../../Character/Player/_Syaro/Syaro.h"
#include "../../Character/Player/_Cocoa/Cocoa.h"
#include "../../Character/Enemy/Enemy.h"


Four::Four(PlayLoad & l_load)
{
	load_ = &l_load;
}

void Four::start()
{
	m_isEnd = false;

	Graphics3D::initialize();
	
	world_.initialize();

	world_.add_camera(new_actor<FourCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 135.0f, "Chiya"),
		new_actor<FourCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 0.0f, "Rize"),
		new_actor<FourCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, 180.0f, "Syaro"),
		new_actor<FourCamera>(world_, Vector3{ 0.0f,25.0f,35.0f }, -45.0f, "Cocoa"));

	world_.add_actor(
		ActorGroup::Chiya,
		new_actor<Chiya>(
			world_, "Chiya",
			Vector3{ 90.0f,0.0f,-150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 135.0f),
			(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana)
	);
	world_.add_actor(
		ActorGroup::Rize,
		new_actor<Rize>(
			world_, "Rize",
			Vector3{ 0.0f,0.0f,540.0f }, Matrix::Identity,
			(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear)
	);
	world_.add_actor(
		ActorGroup::Syaro,
		new_actor<Syaro>(
			world_, "Syaro", 
			Vector3{ Vector3{ 0.0f,0.0f,-540.0f } }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
			(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun)
	);
	world_.add_actor(
		ActorGroup::Cocoa,
		new_actor<Cocoa>(
			world_, "Cocoa",
			Vector3{ -90.0f,0.0f,150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, -45.0f),
			(int)ModelCharaID::Cocoa)
	);
}

void Four::update(float deltaTime)
{
	world_.update(deltaTime);

	EndCheck();
}

void Four::draw() const
{
	//画面のクリア
	Graphics3D::clear();

	SkyBox::bind(0);
	CollisionMesh::bind(0);

	world_.draw();
	world_.draw2();
	world_.draw3();
	world_.draw4();

	frameCamera_.drawFour();
}

bool Four::is_end() const
{
	return m_isEnd;
}

SceneID Four::next() const
{
	return SceneID::StartUp;
}

void Four::end()
{
	world_.clear();

	//ゲームモードのリソースアンロード
	load_->UnLoad();

	Graphics3D::finalize();
}

void Four::EndCheck()
{
	if (!world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown()
			&& world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown()
			&& world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
		{
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown()
			&& world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
		{
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown()
			&& world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
		{
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown()
			&& world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown())
		{
			m_isEnd = true;
		}
	}
}
