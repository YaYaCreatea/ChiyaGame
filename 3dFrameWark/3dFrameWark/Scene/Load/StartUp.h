#ifndef _START_UP_H_
#define _START_UP_H_

#include "../../Scene/IScene.h"

#include "../../AssetsLoad/StartUpLoad/StartUpLoad.h"

class StartUp :public IScene
{
public:
	StartUp(StartUpLoad& l_load);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	StartUpLoad* load_{ nullptr };

	bool m_isEnd;
	float m_nextTimer;
};

#endif