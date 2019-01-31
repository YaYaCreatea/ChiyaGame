#ifndef _TO_PLAY_H_
#define _TO_PLAY_H_

#include "../../Scene/IScene.h"

#include "../../AssetsLoad/PlayLoad/PlayLoad.h"

#include "../SceneParameters.h"

class ToPlay :public IScene
{
public:
	ToPlay(SceneParameters& l_sceneParameters, PlayLoad& l_load);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	SceneParameters* sceneParameters_{ nullptr };
	PlayLoad* load_{ nullptr };

	bool m_isEnd;
	float m_nextTimer;
};

#endif