#include "Duel.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"
#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"

#include "../../Character/Player/Player.h"
#include "../../Character/Player/_Chiya/Chiya.h"
#include "../../Character/Player/_Rize/Rize.h"
#include "../../Character/Player/_Syaro/Syaro.h"
#include "../../Character/Player/_Cocoa/Cocoa.h"
#include "../../Character/Enemy/Boss0/Boss0.h"


Duel::Duel(CharacterSelecter& l_selecter, PlayLoad & l_load)
{
	charaSelecter_ = &l_selecter;
	load_ = &l_load;

	frameCamera_.initialize(l_selecter);
}

void Duel::start()
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
			new_actor<Chiya>(world_, "Chiya", Vector3{ 0.0f,0.0f,-540.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana,
				m_numChiya)
		);

	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
	{
		m_numRize = 1;
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<Rize>(world_, "Rize", Vector3{ 0.0f,0.0f,-540.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear,
				m_numRize)
		);
	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
	{
		m_numSyaro = 1;
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<Syaro>(world_, "Syaro", Vector3{ 0.0f,0.0f,-540.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun,
				m_numSyaro)
		);
	}
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
	{
		m_numCocoa = 1;
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<Cocoa>(world_, "Cocoa", Vector3{ 0.0f,0.0f,-540.0f },
				Matrix::CreateFromAxisAngle(Vector3::Up, 180.0f),
				(int)ModelCharaID::Cocoa,
				m_numCocoa)
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
				m_numChiya)
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
				m_numRize)
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
				m_numSyaro)
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
				m_numCocoa)
		);
	}
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

	if (charaSelecter_->Get_1PChara() == CharaID::Chiya)
		world_.draw();
	else if (charaSelecter_->Get_1PChara() == CharaID::Rize)
		world_.draw2();
	else if (charaSelecter_->Get_1PChara() == CharaID::Syaro)
		world_.draw3();
	else if (charaSelecter_->Get_1PChara() == CharaID::Cocoa)
		world_.draw4();

	if (charaSelecter_->Get_2PChara() == CharaID::Chiya)
		world_.draw();
	else if (charaSelecter_->Get_2PChara() == CharaID::Rize)
		world_.draw2();
	else if (charaSelecter_->Get_2PChara() == CharaID::Syaro)
		world_.draw3();
	else if (charaSelecter_->Get_2PChara() == CharaID::Cocoa)
		world_.draw4();

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
	auto l_chiya = world_.find_actor(ActorGroup::Chiya, "Chiya");
	auto l_rize = world_.find_actor(ActorGroup::Rize, "Rize");
	auto l_syaro = world_.find_actor(ActorGroup::Syaro, "Syaro");
	auto l_cocoa = world_.find_actor(ActorGroup::Cocoa, "Cocoa");

	if (l_chiya != nullptr)
	{
		if (!l_chiya->get_IsDown())
		{
			if (l_rize != nullptr)
			{
				if(l_rize->get_IsDown())
					m_isEnd = true;
			}
			else if (l_syaro != nullptr)
			{
				if (l_syaro->get_IsDown())
					m_isEnd = true;
			}
			else if (l_cocoa != nullptr)
			{
				if (l_cocoa->get_IsDown())
					m_isEnd = true;
			}
		}
	}
	if (l_rize != nullptr)
	{
		if (!l_rize->get_IsDown())
		{
			if (l_chiya != nullptr)
			{
				if (l_chiya->get_IsDown())
					m_isEnd = true;
			}
			else if (l_syaro != nullptr)
			{
				if (l_syaro->get_IsDown())
					m_isEnd = true;
			}
			else if (l_cocoa != nullptr)
			{
				if (l_cocoa->get_IsDown())
					m_isEnd = true;
			}
		}
	}
	if (l_syaro != nullptr)
	{
		if (!l_syaro->get_IsDown())
		{
			if (l_chiya != nullptr)
			{
				if (l_chiya->get_IsDown())
					m_isEnd = true;
			}
			else if (l_rize != nullptr)
			{
				if (l_rize->get_IsDown())
					m_isEnd = true;
			}
			else if (l_cocoa != nullptr)
			{
				if (l_cocoa->get_IsDown())
					m_isEnd = true;
			}
		}
	}
	if (l_cocoa != nullptr)
	{
		if (!l_cocoa->get_IsDown())
		{
			if (l_chiya != nullptr)
			{
				if (l_chiya->get_IsDown())
					m_isEnd = true;
			}
			else if (l_rize != nullptr)
			{
				if (l_rize->get_IsDown())
					m_isEnd = true;
			}
			else if (l_syaro != nullptr)
			{
				if (l_syaro->get_IsDown())
					m_isEnd = true;
			}
		}
	}
}
