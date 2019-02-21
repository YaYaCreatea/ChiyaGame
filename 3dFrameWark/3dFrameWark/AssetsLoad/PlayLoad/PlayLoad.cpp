#include "PlayLoad.h"

#include "../../assetsID/AssetsID.h"

#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../SkeletalMesh/SkeletalMesh.h"
#include "../../StaticMesh/StaticMesh.h"
#include "../../Billboard/Billboard.h"
#include "../../Effect/Effect.h"


PlayLoad::PlayLoad()
{

}

PlayLoad::~PlayLoad()
{
}

void PlayLoad::Load()
{
	m_loadNum = 0;

	SkeletalMesh::initialize();
	StaticMesh::initialize();
	Graphics2D::initialize();
	Billboard::initialize();
	//Effect::initialize();

	SetUseASyncLoadFlag(TRUE);

	//3D���f���̓ǂݍ���
	SkeletalMesh::load((int)ModelCharaID::Chiya, "asset/Chiya2/���.mv1");
	SkeletalMesh::load((int)ModelCharaID::Rize, "asset/Rize/���[.mv1");
	SkeletalMesh::load((int)ModelCharaID::Syaro, "asset/Syaro/�V����.mv1");
	SkeletalMesh::load((int)ModelCharaID::Cocoa, "asset/Cocoa/�R�R�A.mv1");
	SkeletalMesh::load((int)ModelCharaID::Boss, "asset/Boss/���b.mv1");

	//�X�^�e�B�b�N���b�V���ǂݍ���
	StaticMesh::load((int)ModelWeaponID::Spear, "asset/weapon/Spear.mv1");
	StaticMesh::load((int)ModelWeaponID::Gun, "asset/weapon/Gun/Gun.mv1");
	StaticMesh::load((int)ModelWeaponID::Katana, "asset/weapon/Katana/Katana.mv1");

	//UI���\�[�X�ǂݍ���
	Graphics2D::load_sprite((int)SpriteID::LoadGauge, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya, "asset/2Dsprite/GamePlay/BackFrame_Chiya.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize, "asset/2Dsprite/GamePlay/BackFrame_Rize.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro, "asset/2Dsprite/GamePlay/BackFrame_Syaro.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa, "asset/2Dsprite/GamePlay/BackFrame_Cocoa.png");
	Graphics2D::load_sprite((int)SpriteID::HpGauge, "asset/2Dsprite/PlayerUI/HpGauge2.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Chiya_4, "asset/2Dsprite/GamePlay/BackFrame_Chiya_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Rize_4, "asset/2Dsprite/GamePlay/BackFrame_Rize_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Syaro_4, "asset/2Dsprite/GamePlay/BackFrame_Syaro_4.png");
	Graphics2D::load_sprite((int)SpriteID::Frame_Cocoa_4, "asset/2Dsprite/GamePlay/BackFrame_Cocoa_4.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOff, "asset/2Dsprite/GamePlay/LockOnArea.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOn, "asset/2Dsprite/GamePlay/LockOnAreaOn.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOff_4, "asset/2Dsprite/GamePlay/LockOnArea_4.png");
	Graphics2D::load_sprite((int)SpriteID::LockOnAreaOn_4, "asset/2Dsprite/GamePlay/LockOnAreaOn_4.png");

	//�r���{�[�h�̓ǂݍ���
	Billboard::load(0, "asset/Particle02.png");
	Billboard::load(1, "asset/2Dsprite/PlayerUI/HpGauge.png");
	Billboard::load(2, "asset/2Dsprite/GamePlay/lockOnCircle.png");

	SetUseASyncLoadFlag(FALSE);

	m_loadNum = GetASyncLoadNum();
}

void PlayLoad::UnLoad()
{
	SkeletalMesh::finalize();
	StaticMesh::finalize();
	CollisionMesh::finalize();
	SkyBox::finalize();
	Billboard::finalize();
	//Effect::finalize();
	Graphics2D::finalize();
}

int PlayLoad::get_loadNum() const
{
	return m_loadNum;
}
