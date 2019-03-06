#ifndef _TITLE_H_
#define _TITLE_H_

#include "../../Scene/IScene.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../Utility/Input/InputState.h"

#include "../Fead/FeadInOut.h"
#include "TitlePerformance.h"

class Title :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	InputState input_;
	bool m_isEnd;
	bool m_isNext;

	TitlePerformance performance_;
	FeadInOut fead_;
};

#endif