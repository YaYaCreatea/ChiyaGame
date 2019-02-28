#ifndef _WINNER_SYARO_H_
#define _WINNER_SYARO_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../AnimatedBlendShape/AnimatedBlendShape.h"

class WinnerSyaro :public Actor
{
public:
	//コンストラクタ
	WinnerSyaro(IWorld& world,
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

private:

	//アニメーションメッシュ
	AnimatedMesh mesh_;
	AnimatedBlendShape shape_;

	//モーション番号
	int m_motion;
	//武器モデル
	int m_weapon;

	//カメラの回転
	Matrix m_cameraRoate;

	float m_timer;
};

#endif