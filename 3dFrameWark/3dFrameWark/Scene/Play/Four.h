#ifndef _FOUR_H_
#define _FOUR_H_

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

#include "../../World/World.h"

#include "../../Camera/FrameCamera/FrameCamera.h"

class Four :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	void EndCheck();

private:
	World world_;
	FrameCamera frameCamera_;

	bool m_isEnd;	//èIóπÉtÉâÉO
};

#endif