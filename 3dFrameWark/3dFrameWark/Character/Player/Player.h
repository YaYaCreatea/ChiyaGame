#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Actor/Actor.h"
#include "../../AnimatedMesh/AnimatedMesh.h"

#include "PlayerStateName.h"

class TpsCamera;

class Player :public Actor
{
public:
	//コンストラクタ
	Player(IWorld& world, const Vector3& l_position, int l_model, int l_weapon);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);

private:
	//状態の更新
	void update_state(float deltaTime);

	//状態遷移
	void change_state(PlayerStateName l_state, int l_motion);

	//移動処理
	void move(float deltaTime);

	//攻撃中
	void attack(float deltaTime);

	void attack2(float deltaTime);

	//ダメージ中
	void damage(float deltaTime);

	//ジャンプ中
	void jump(float deltaTime);

	//移動量
	void input_velocity(float l_forward_speed, float l_side_speed);

	//振り向き
	void face_to_orientation(float deltaTime, float l_forward_velo);

	//武器の描画
	void draw_weapon()const;

private:
	const float WALKSPEED{ 1.0f };
	const float GRAVITY{ -0.04f };

	AnimatedMesh mesh_;		//アニメーションメッシュ

	Matrix m_cameraRoate;
	float m_yaw;
	float m_yawroate;

	int m_jumpCount;

	Vector3 m_test;

	PlayerStateName m_state;//状態

	int m_motion;			//モーション番号
	int m_weapon;			//武器モデル

	float m_state_timer;	//状態タイマー
};

#endif