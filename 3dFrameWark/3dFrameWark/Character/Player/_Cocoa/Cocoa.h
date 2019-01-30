#ifndef _COCOA_H_
#define _COCOA_H_

#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../Utility/Input/InputState.h"

#include "../PlayerStateName.h"
#include "../PlayerActionBase.h"
#include "../PlayerActionBaseManager.h"
#include "../PlayerActionPtr.h"

#include "../PlayerParameters.h"

#include <map>

class Cocoa :public Actor
{
public:
	//コンストラクタ
	Cocoa(IWorld& world, std::string l_name, const Vector3& l_position, Matrix l_rotate, int l_model);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:

	//おっぱい揺れ
	void oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass);

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

	//モーション番号
	int m_motion;
	//武器モデル
	int m_weapon;

	//カメラの回転
	Matrix m_cameraRoate;

	//おっぱい変数
	Vector3 m_pi;
	Vector3 m_piVelo;
};

#endif