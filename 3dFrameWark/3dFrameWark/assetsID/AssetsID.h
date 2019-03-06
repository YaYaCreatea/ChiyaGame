#ifndef _ASSETS_ID_H_
#define _ASSETS_ID_H_

//�L�������f���A�Z�b�gID
enum class ModelCharaID
{
	Chiya,
	Rize,
	Syaro,
	Cocoa,
	Boss,
};

//���탂�f���A�Z�b�gID
enum class ModelWeaponID
{
	Spear,
	Gun,
	Katana,
};

//2D�X�v���C�g�A�Z�b�gID
enum class SpriteID
{
	TitleBack,
	TitleLogo,
	TitleCharaBack,
	TitleCharaBackFlash,
	PAS,
	Frame_Chiya,
	Frame_Rize,
	Frame_Syaro,
	Frame_Cocoa,
	HpGauge,
	HpFrame,
	Mode1on1_Act,
	Mode1on1_Dact,
	ModeFour_Act,
	ModeFour_Dact,
	Frame_Chiya_4,
	Frame_Rize_4,
	Frame_Syaro_4,
	Frame_Cocoa_4,
	LoadGauge,
	LoadFrame,
	NLLogo,
	LockOnAreaOff,
	LockOnAreaOn,
	LockOnAreaOff_4,
	LockOnAreaOn_4,
	CharaSelectBack,
	CharaSelectChiya,
	CharaSelectRize,
	CharaSelectSyaro,
	CharaSelectCocoa,
	SelICO_1_D,
	SelICO_1_0,
	SelICO_1_1,
	SelICO_1_2,
	SelICO_1_3,
	SelICO_2_D,
	SelICO_2_0,
	SelICO_2_1,
	SelICO_2_2,
	SelICO_2_3,
	SelICO_3_D,
	SelICO_3_0,
	SelICO_3_1,
	SelICO_3_2,
	SelICO_3_3,
	SelICO_4_D,
	SelICO_4_0,
	SelICO_4_1,
	SelICO_4_2,
	SelICO_4_3,
	ResultBackChiya,
	ResultBackRize,
	ResultBackSyaro,
	ResultBackCocoa,
	BlackOutBack,
};

//�r���{�[�h�A�Z�b�gID
enum class BillBoardID
{
	Hit,
	GunShot,
	MagicShot
};

//BGM�A�Z�b�gID
enum class SoundID_BGM
{
	Title,
	ModeSelect,
	CharaSelect,
	GameBGM,
	Result,
};

//SE�A�Z�b�gID
enum class SoundID_SE
{
	Chiya_Select,
	Chiya_Attack1,
	Chiya_Attack2,
	Chiya_Damage,
	Chiya_Down,
	Chiya_Win,
	Rize_Select,
	Rize_Attack1,
	Rize_Attack2,
	Rize_Attack3,
	Rize_Attack4,
	Rize_Damage,
	Rize_Down,
	Rize_Win,
	Syaro_Select,
	Syaro_Attack1,
	Syaro_Attack2,
	Syaro_Damage,
	Syaro_Down,
	Syaro_Win,
	Cocoa_Select,
	Cocoa_Attack1,
	Cocoa_Attack2,
	Cocoa_Damage,
	Cocoa_Down,
	Cocoa_Win,
	Dash,
	GunShot,
	KatanaSlash,
	SystemStart,
	SystemSelect,
	SystemCursor,
};

#endif