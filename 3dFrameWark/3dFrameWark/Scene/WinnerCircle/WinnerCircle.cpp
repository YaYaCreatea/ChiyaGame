#include "WinnerCircle.h"

#include "../../assetsID/AssetsID.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../Graphics3D/Graphics3D.h"
#include "../../Sound/Sound.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../Character/ResultPlayer/Chiya/WinnerChiya.h"
#include "../../Character/ResultPlayer/Rize/WinnerRize.h"
#include "../../Character/ResultPlayer/Syaro/WinnerSyaro.h"
#include "../../Character/ResultPlayer/Cocoa/WinnerCocoa.h"

WinnerCircle::WinnerCircle(PlayLoad & l_load, WinnerCharacter& l_winner)
{
	load_ = &l_load;
	winner_ = &l_winner;
}

void WinnerCircle::start()
{
	m_isEnd = false;
	input_.initialize(DX_INPUT_PAD1);

	Graphics3D::initialize();

	world_.initialize();

	if (winner_->Get_Winner() == CharaID::Chiya)
	{
		world_.add_actor(
			ActorGroup::Chiya,
			new_actor<WinnerChiya>(world_, "Chiya", Vector3{ 0.0f,0.0f,0.0f },
				Matrix::Identity,
				(int)ModelCharaID::Chiya, (int)ModelWeaponID::Katana)
		);
	}
	else if (winner_->Get_Winner() == CharaID::Rize)
	{
		world_.add_actor(
			ActorGroup::Rize,
			new_actor<WinnerRize>(world_, "Rize", Vector3{ 0.0f,0.0f,0.0f },
				Matrix::Identity,
				(int)ModelCharaID::Rize, (int)ModelWeaponID::Spear)
		);
	}
	else if (winner_->Get_Winner() == CharaID::Syaro)
	{
		world_.add_actor(
			ActorGroup::Syaro,
			new_actor<WinnerSyaro>(world_, "Syaro", Vector3{ 0.0f,0.0f,0.0f },
				Matrix::Identity,
				(int)ModelCharaID::Syaro, (int)ModelWeaponID::Gun)
		);
	}
	else if (winner_->Get_Winner() == CharaID::Cocoa)
	{
		world_.add_actor(
			ActorGroup::Cocoa,
			new_actor<WinnerCocoa>(world_, "Cocoa", Vector3{ 0.0f,0.0f,0.0f },
				Matrix::Identity,
				(int)ModelCharaID::Cocoa)
		);
	}

	Sound::play_bgm((int)SoundID_BGM::Result);
}

void WinnerCircle::update(float deltaTime)
{
	input_.update();

	world_.update(deltaTime);

	if (input_.Trigger(PAD_INPUT_1))
		m_isEnd = true;
}

void WinnerCircle::draw() const
{
	Graphics3D::clear();

	if (winner_->Get_Winner() == CharaID::Chiya)
	{
		world_.draw();
		Graphics2D::draw_sprite((int)SpriteID::ResultBackChiya, Vector2::Zero);
	}
	else if (winner_->Get_Winner() == CharaID::Rize)
	{
		world_.draw2();
		Graphics2D::draw_sprite((int)SpriteID::ResultBackRize, Vector2::Zero);
	}
	else if (winner_->Get_Winner() == CharaID::Syaro)
	{
		world_.draw3();
		Graphics2D::draw_sprite((int)SpriteID::ResultBackSyaro, Vector2::Zero);
	}
	else if (winner_->Get_Winner() == CharaID::Cocoa)
	{
		world_.draw4();
		Graphics2D::draw_sprite((int)SpriteID::ResultBackCocoa, Vector2::Zero);
	}
}

bool WinnerCircle::is_end() const
{
	return m_isEnd;
}

SceneID WinnerCircle::next() const
{
	return SceneID::StartUp;
}

void WinnerCircle::end()
{
	world_.clear();

	winner_->initialize();

	//ゲームモードのリソースアンロード
	load_->UnLoad();

	Graphics3D::finalize();
}
