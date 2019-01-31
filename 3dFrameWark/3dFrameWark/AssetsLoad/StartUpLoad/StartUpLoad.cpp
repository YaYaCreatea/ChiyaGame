#include "StartUpLoad.h"

#include "../../assetsID/AssetsID.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"
#include "../../Graphics2D/Graphics2D.h"

StartUpLoad::StartUpLoad()
{
}

StartUpLoad::~StartUpLoad()
{
}

void StartUpLoad::Load()
{
	m_loadNum = 0;

	Graphics2D::initialize();
	CollisionMesh::initialize();
	SkyBox::initialize();

	SetUseASyncLoadFlag(TRUE);	

	Graphics2D::load_sprite((int)SpriteID::LoadGauge, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Graphics2D::load_sprite((int)SpriteID::TitleBack, "asset/2Dsprite/Title/TitleBack.png");
	Graphics2D::load_sprite((int)SpriteID::Mode1on1_Act, "asset/2Dsprite/ModeSelect/Mode1on1_Act.png");
	Graphics2D::load_sprite((int)SpriteID::Mode1on1_Dact, "asset/2Dsprite/ModeSelect/Mode1on1_Dact.png");
	Graphics2D::load_sprite((int)SpriteID::ModeFour_Act, "asset/2Dsprite/ModeSelect/ModeFour_Act.png");
	Graphics2D::load_sprite((int)SpriteID::ModeFour_Dact, "asset/2Dsprite/ModeSelect/ModeFour_Dact.png");

	CollisionMesh::load(0, "asset/Stage/StageTest/Stage4.mv1");
	SkyBox::load(0, "asset/skybox/Dome_SS601.mv1");

	SetUseASyncLoadFlag(FALSE);

	m_loadNum = GetASyncLoadNum();
}

void StartUpLoad::UnLoad()
{
	Graphics2D::finalize();
}

int StartUpLoad::get_loadNum() const
{
	return m_loadNum;
}
