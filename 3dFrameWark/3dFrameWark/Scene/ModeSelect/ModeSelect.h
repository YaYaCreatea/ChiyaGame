#ifndef _MODE_SELECT_H_
#define _MODE_SELECT_H_

#include "../../Scene/IScene.h"

#include "../../Utility/Input/InputState.h"
#include "../../Graphics2D/Graphics2D.h"

#include "../SceneID.h"
#include "ModeID.h"

#include "../../Camera/ModeSelectCamera/ModeSelectCamera.h"

class ModeSelect :public IScene
{
public:
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	ModeSelectCamera camera_;

	ModeID m_modeID;
	SceneID m_nextSceneID;

	InputState input_;
	bool m_isEnd;	//èIóπÉtÉâÉO
};

#endif