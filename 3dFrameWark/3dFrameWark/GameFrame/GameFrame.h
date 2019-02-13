#ifndef _GAME_FRAME_H_
#define _GAME_FRAME_H_

#include "../Game/Game.h"
#include "../SceneManager/SceneManager.h"
#include "../Scene/SceneParameters.h"
#include "../Scene/CharaSelect/CharacterSelecter.h"

#include "../AssetsLoad/StartUpLoad/StartUpLoad.h"
#include "../AssetsLoad/PlayLoad/PlayLoad.h"

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
	SceneManager sceneManager_;
	SceneParameters sceneParameters_;
	CharacterSelecter selecter_;

	StartUpLoad startUpload_;
	PlayLoad playload_;
};

#endif