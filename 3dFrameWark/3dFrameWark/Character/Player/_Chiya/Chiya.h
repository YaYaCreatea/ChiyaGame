#ifndef _CHIYA_H_
#define _CHIYA_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../Utility/Input/InputState.h"

#include "../PlayerStateName.h"
#include "../PlayerActionBase.h"
#include "../PlayerActionBaseManager.h"
#include "../PlayerActionPtr.h"

#include "../PlayerParameters.h"

#include <map>

class Chiya :public Actor
{
public:
	//コンストラクタ
	Chiya(IWorld& world,
		std::string l_name, const Vector3& l_position, Matrix l_rotate,
		int l_model, int l_weapon,
		int l_numPlayer, int l_gMode = 0
	);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:

	//武器の描画
	void draw_weapon()const;

	//おっぱい揺れ
	void oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

	void lockOnCheck();

private:

	//アクション管理
	using ActionMap = std::map<PlayerStateName, PlayerActionBaseManager>;
	ActionMap playerActions_;

	//アニメーションメッシュ
	AnimatedMesh mesh_;

	InputState input_;

	//プレイヤーのパラメータ類
	PlayerParameters parameters_;

	//プレイヤー状態
	PlayerStateName m_state;

	int m_numPlayer;
	int m_gameMode;

	//モーション番号
	int m_motion;
	//武器モデル
	int m_weapon;

	//カメラの回転
	Matrix m_cameraRoate;

	//おっぱい変数
	Vector3 m_pi;
	Vector3 m_piVelo;

	Vector3 m_forward;
};

#endif