#ifndef _GAME_PLAY_H_
#define _GAME_PLAY_H_

#include "../../Scene/IScene.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../SkeletalMesh/SkeletalMesh.h"
#include "../../StaticMesh/StaticMesh.h"
#include "../../CollisionMesh/CollisionMesh.h"
#include "../../SkyBox/SkyBox.h"
#include "../../Billboard/Billboard.h"
#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Input/GamePad/GamePad.h"

#include "../../World/World.h"

class GamePlay :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	World world_;
	bool m_isEnd;	//èIóπÉtÉâÉO
};

#endif