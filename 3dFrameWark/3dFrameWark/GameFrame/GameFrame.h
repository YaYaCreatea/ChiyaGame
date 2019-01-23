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
	World world_;
};

#endif