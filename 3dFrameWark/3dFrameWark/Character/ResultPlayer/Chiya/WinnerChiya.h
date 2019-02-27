#ifndef _WINNER_CHIYA_H_
#define _WINNER_CHIYA_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"

class WinnerChiya :public Actor
{
public:
	//コンストラクタ
	WinnerChiya(IWorld& world,
		std::string l_name, const Vector3& l_position, Matrix l_rotate,
		int l_model, int l_weapon
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

private:

	//アニメーションメッシュ
	AnimatedMesh mesh_;

	//モーション番号
	int m_motion;
	//武器モデル
	int m_weapon;

	//カメラの回転
	Matrix m_cameraRoate;

	//おっぱい変数
	Vector3 m_pi;
	Vector3 m_piVelo;

	float m_timer;
};

#endif