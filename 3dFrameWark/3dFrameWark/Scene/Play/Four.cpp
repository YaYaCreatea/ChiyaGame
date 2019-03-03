#include "Four.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"
#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"
#include "../../Sound/Sound.h"

#include "../../Camera/FourCamera/FourCamera.h"
#include "../../Character/Player/_Chiya/Chiya.h"
#include "../../Character/Player/_Rize/Rize.h"
#include "../../Character/Player/_Syaro/Syaro.h"
#include "../../Character/Player/_Cocoa/Cocoa.h"
#include "../../Character/Enemy/Enemy.h"


Four::Four(CharacterSelecter& l_selecter, PlayLoad & l_load, WinnerCharacter& l_winner)
{
	charaSelecter_ = &l_selecter;
	load_ = &l_load;
	winner_ = &l_winner;

	frameCamera_.initialize(l_selecter);
}

void Four::start()
{
	m_isEnd = false;

	m_numChiya = 0;
	m_numRize = 0;
	m_numSyaro = 0;
	m_numCocoa = 0;

	Graphics3D::initialize();

	world_.initialize();

	if (charaSelecter_->Get_1PChara() == CharaID::Chiya)
	{
		m_numChiya = 1;
		world_.add_actor(
			ActorGroup::Chiya,
			new_actor<Chiya>(world_, "Chiya",
				Vector3{ 90.0f,0.0f,-150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 135.0f),
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana,
				m_numChiya, 1)
		);

	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
	{
		m_numRize = 1;
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<Rize>(world_, "Rize",
				Vector3{ 90.0f,0.0f,-150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 135.0f),
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear,
				m_numRize, 1)
		);
	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
	{
		m_numSyaro = 1;
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<Syaro>(world_, "Syaro",
				Vector3{ 90.0f,0.0f,-150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 135.0f),
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun,
				m_numSyaro, 1)
		);
	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
	{
		m_numCocoa = 1;
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<Cocoa>(world_, "Cocoa",
				Vector3{ 90.0f,0.0f,-150.0f }, Matrix::CreateFromAxisAngle(Vector3::Up, 135.0f),
				(int)ModelCharaID::Cocoa,
				m_numCocoa, 1)
		);
	}

	if (charaSelecter_->Get_2PChara() == CharaID::Chiya)
	{
		m_numChiya = 2;
		world_.add_actor(
			ActorGroup::Chiya,
			new_actor<Chiya>(world_, "Chiya", Vector3{ 0.0f,0.0f,540.0f },
				Matrix::Identity,
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana,
				m_numChiya, 1)
		);
	}
	else if (charaSelecter_->Get_2PChara() == CharaID::Rize)
	{
		m_numRize = 2;
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<Rize>(world_, "Rize", Vector3{ 0.0f,0.0f,540.0f },
				Matrix::Identity,
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear,
				m_numRize, 1)
		);
	}
	else if (charaSelecter_->Get_2PChara() == CharaID::Syaro)
	{
		m_numSyaro = 2;
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<Syaro>(world_, "Syaro", Vector3{ 0.0f,0.0f,540.0f },
				Matrix::Identity,
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun,
				m_numSyaro, 1)
		);
	}
	else if (charaSelecter_->Get_2PChara() == CharaID::Cocoa)
	{
		m_numCocoa = 2;
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<Cocoa>(world_, "Cocoa", Vector3{ 0.0f,0.0f,540.0f },
				Matrix::Identity,
				(int)ModelCharaID::Cocoa,
				m_numCocoa, 1)
		);
	}

	if (charaSelecter_->Get_3PChara() == CharaID::Chiya)
	{
		m_numChiya = 3;
		world_.add_actor(
			ActorGroup::Chiya,
			new_actor<Chiya>(world_, "Chiya",
				Vector3{ Vector3{ 0.0f,0.0f,-540.0f } }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana,
				m_numChiya, 1)
		);
	}
	else if (charaSelecter_->Get_3PChara() == CharaID::Rize)
	{
		m_numRize = 3;
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<Rize>(world_, "Rize",
				Vector3{ Vector3{ 0.0f,0.0f,-540.0f } }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear,
				m_numRize, 1)
		);
	}
	else if (charaSelecter_->Get_3PChara() == CharaID::Syaro)
	{
		m_numSyaro = 3;
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<Syaro>(world_, "Syaro",
				Vector3{ Vector3{ 0.0f,0.0f,-540.0f } }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun,
				m_numSyaro, 1)
		);
	}
	else if (charaSelecter_->Get_3PChara() == CharaID::Cocoa)
	{
		m_numCocoa = 3;
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<Cocoa>(world_, "Cocoa",
				Vector3{ Vector3{ 0.0f,0.0f,-540.0f } }, Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Cocoa,
				m_numCocoa, 1)
		);
	}

	if (charaSelecter_->Get_4PChara() == CharaID::Chiya)
	{
		m_numChiya = 4;
		world_.add_actor(
			ActorGroup::Chiya,
			new_actor<Chiya>(world_, "Chiya", Vector3{ -90.0f,0.0f,150.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, -45.0f),
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana,
				m_numChiya, 1)
		);
	}
	else if (charaSelecter_->Get_4PChara() == CharaID::Rize)
	{
		m_numRize = 4;
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<Rize>(world_, "Rize", Vector3{ -90.0f,0.0f,150.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, -45.0f),
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear,
				m_numRize, 1)
		);
	}
	else if (charaSelecter_->Get_4PChara() == CharaID::Syaro)
	{
		m_numSyaro = 4;
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<Syaro>(world_, "Syaro", Vector3{ -90.0f,0.0f,150.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, -45.0f),
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun,
				m_numSyaro, 1)
		);
	}
	else if (charaSelecter_->Get_4PChara() == CharaID::Cocoa)
	{
		m_numCocoa = 4;
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<Cocoa>(world_, "Cocoa", Vector3{ -90.0f,0.0f,150.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, -45.0f),
				(int)ModelCharaID::Cocoa,
				m_numCocoa, 1)
		);
	}

	fead_.Initialize();

	Sound::play_bgm((int)SoundID_BGM::GameBGM);
}

void Four::update(float deltaTime)
{
	fead_.FeadOut(deltaTime);
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

	fead_.DrawBack();
}

bool Four::is_end() const
{
	return m_isEnd;
}

SceneID Four::next() const
{
	return SceneID::Result;
}

void Four::end()
{
	world_.clear();

	//ゲームモードのリソースアンロード
	//load_->UnLoad();

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
			winner_->Set_Winner(CharaID::Chiya);
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown()
			&& world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
		{
			winner_->Set_Winner(CharaID::Rize);
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown()
			&& world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
		{
			winner_->Set_Winner(CharaID::Syaro);
			m_isEnd = true;
		}
	}
	else if (!world_.find_actor(ActorGroup::Cocoa, "Cocoa")->get_IsDown())
	{
		if (world_.find_actor(ActorGroup::Chiya, "Chiya")->get_IsDown()
			&& world_.find_actor(ActorGroup::Rize, "Rize")->get_IsDown()
			&& world_.find_actor(ActorGroup::Syaro, "Syaro")->get_IsDown())
		{
			winner_->Set_Winner(CharaID::Cocoa);
			m_isEnd = true;
		}
	}
}
