#ifndef _NULL_SCENE_H_
#define _NULL_SCENE_H_

#include "../../Scene/IScene.h"

class NullScene :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;
};

#endif