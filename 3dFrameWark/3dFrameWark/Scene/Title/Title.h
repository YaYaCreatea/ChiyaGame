#ifndef _TITLE_H_
#define _TITLE_H_

#include "../../Scene/IScene.h"

#include "../../Utility/Input/InputState.h"

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
	bool m_isEnd;	//I—¹ƒtƒ‰ƒO
};

#endif