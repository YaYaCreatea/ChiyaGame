#ifndef _WINNER_COCOA_H_
#define _WINNER_COCOA_H_

#include "../../../Actor/ActorPtr.h"
#include "../../../Actor/Actor.h"
#include "../../../AnimatedMesh/AnimatedMesh.h"
#include "../../../AnimatedBlendShape/AnimatedBlendShape.h"

class WinnerCocoa :public Actor
{
public:
	//コンストラクタ
	WinnerCocoa(IWorld& world,
		std::string l_name, const Vector3& l_position, Matrix l_rotate,
		int l_model
	);

	virtual void update(float deltaTime)override;

	virtual void draw()const override;

	virtual void react(Actor& other)override;

	virtual void handle_message(EventMessage message, void* param);


private:

	//アニメーションメッシュ
	AnimatedMesh mesh_;
	AnimatedBlendShape shape_;

	//モーション番号
	int m_motion;

	//カメラの回転
	Matrix m_cameraRoate;

	float m_timer;
};

#endif