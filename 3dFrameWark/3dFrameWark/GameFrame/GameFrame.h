#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include "../Game/Game.h"
#include "../SceneManager/SceneManager.h"

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
	//World world_;
	SceneManager sceneManager_;
};

#endif