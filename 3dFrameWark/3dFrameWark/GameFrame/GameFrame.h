#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include "../Game/Game.h"
#include "../Graphics3D/Graphics3D.h"
#include "../Graphics2D/Graphics2D.h"
#include "../SkeletalMesh/SkeletalMesh.h"
#include "../StaticMesh/StaticMesh.h"
#include "../CollisionMesh/CollisionMesh.h"
#include "../SkyBox/SkyBox.h"
#include "../Billboard/Billboard.h"
#include "../Utility/Matrix/Matrix.h"
#include "../Utility/Vector3/Vector3.h"
#include "../Utility/Input/GamePad/GamePad.h"

#include "../World/World.h"

class GameFrame :public Game
{
public:
	//コンストラクタ
	GameFrame();

private:

	//開始
	void start()override;

	//更新
	void update(float deltaTime)override;

	//描画
	void draw()override;

	//終了
	void end()override;

private:
	World world_;
};

#endif