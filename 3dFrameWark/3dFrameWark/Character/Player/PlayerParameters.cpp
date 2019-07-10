#include "PlayerParameters.h"

#include "../../Utility/MathHelper/MathHelper.h"

PlayerParameters::PlayerParameters()
{
}

//初期化
void PlayerParameters::Initialize(std::string l_name, int l_Hp)
{
	m_name = l_name;
	m_Hp = l_Hp;
	m_HpMax = l_Hp;
	m_state_timer = 0.0f;
	m_end_time = 0.0f;
	m_breakDirection = Vector3::Zero;
	m_lockOnDirection = Vector3::Zero;
	m_distanceNear = 0.0f;
	m_distanceToChiya = 0.0f;
	m_distanceToRize = 0.0f;
	m_distanceToSyaro = 0.0f;
	m_distanceToCocoa = 0.0f;
	m_isLockOn = true;
	m_isDown = false;
}

// アニメーション状態タイマー設定
void PlayerParameters::Set_StateTimer(float l_state_timer)
{
	m_state_timer = l_state_timer;
}

// アニメーション状態タイマー追加
void PlayerParameters::Add_StateTimer(float l_state_timer)
{
	m_state_timer += l_state_timer;
}

// アニメーション状態タイマー取得
float PlayerParameters::Get_StateTimer() const
{
	return m_state_timer;
}

// アニメーション終了時間設定
void PlayerParameters::Set_EndTime(float l_end_time)
{
	m_end_time = l_end_time;
}

// アニメーション終了時間取得
float PlayerParameters::Get_EndTime() const
{
	return m_end_time;
}

// 重力の取得
float PlayerParameters::Get_Gravity() const
{
	return GRAVITY;
}

// 自分のActorグループの設定
void PlayerParameters::Set_MyGroup(ActorGroup l_myGoup)
{
	m_myGroup = l_myGoup;
}

// 自分のActorグループの取得
ActorGroup PlayerParameters::Get_MyGroup() const
{
	return m_myGroup;
}

// 名前の取得
std::string PlayerParameters::Get_Name() const
{
	return m_name;
}

// HP(ダメージ処理)
void PlayerParameters::Damage_HP(int l_damageHp)
{
	m_Hp = MathHelper::ClampInt(m_Hp - l_damageHp, 0, m_HpMax);
}

// 現在のHPの取得
int PlayerParameters::Get_HP() const
{
	return m_Hp;
}

// HPの最大値の取得
int PlayerParameters::Get_MaxHP() const
{
	return m_HpMax;
}

// Break方向の設定
void PlayerParameters::Set_BreakDirection(Vector3 l_direction)
{
	m_breakDirection = l_direction;
}

// Break方向の取得
Vector3 PlayerParameters::Get_BreakDirection() const
{
	return m_breakDirection;
}

// ロックオン方向の設定
void PlayerParameters::Set_LockOnDirection(Vector3 l_direction)
{
	m_lockOnDirection = l_direction;
}

// ロックオン方向正規化
void PlayerParameters::LockOnDirectionNormlize()
{
	m_lockOnDirection.Normalize();
}

// ロックオン方向の取得
Vector3 PlayerParameters::Get_LockOnDirection() const
{
	return m_lockOnDirection;
}

// ロックオン状態の設定
void PlayerParameters::LockOn(bool l_isLockOn)
{
	m_isLockOn = l_isLockOn;
}

// ロックオン状態の取得
bool PlayerParameters::Get_IsLockOn() const
{
	return m_isLockOn;
}

// 一番近い距離の設定
void PlayerParameters::Set_DistanceNear(float l_distance)
{
	m_distanceNear = l_distance;
}

// 千夜までの距離の設定
void PlayerParameters::Set_DistanceToChiya(float l_distance)
{
	m_distanceToChiya = l_distance;
}

// リゼまでの距離の設定
void PlayerParameters::Set_DistanceToRize(float l_distance)
{
	m_distanceToRize = l_distance;
}

// シャロまでの距離の設定
void PlayerParameters::Set_DistanceToSyaro(float l_distance)
{
	m_distanceToSyaro = l_distance;
}

// ココアまでの距離の設定
void PlayerParameters::Set_DistanceToCocoa(float l_distance)
{
	m_distanceToCocoa = l_distance;
}

// 一番近い距離の取得
float PlayerParameters::Get_DistanceNear() const
{
	return m_distanceNear;
}

// 千夜までの距離の取得
float PlayerParameters::Get_DistanceToChiya() const
{
	return m_distanceToChiya;
}

// リゼまでの距離の取得
float PlayerParameters::Get_DistanceToRize() const
{
	return m_distanceToRize;
}

// シャロまでの距離の取得
float PlayerParameters::Get_DistanceToSyaro() const
{
	return m_distanceToSyaro;
}

// ココアまでの距離の取得
float PlayerParameters::Get_DistanceToCocoa() const
{
	return m_distanceToCocoa;
}

// ダウンしたかの設定
void PlayerParameters::DidDown()
{
	m_isDown = true;
}

// ダウンしたかの取得
bool PlayerParameters::Get_IsDown() const
{
	return m_isDown;
}
