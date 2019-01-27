#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include "../Game/Game.h"
#include "../SceneManager/SceneManager.h"

class GameFrame :public Game
{
public:
	//�R���X�g���N�^
	GameFrame();

private:

	//�J�n
	void start()override;

	//�X�V
	void update(float deltaTime)override;

	//�`��
	void draw()override;

	//�I��
	void end()override;

private:
	//World world_;
	SceneManager sceneManager_;
};

#endif