#ifndef _MODE_SELECT_H_
#define _MODE_SELECT_H_

#include "../../Scene/IScene.h"

#include "../SceneID.h"
#include "ModeID.h"

#include "../../Camera/ModeSelectCamera/ModeSelectCamera.h"
#include "../../Utility/Input/InputState.h"

#include "../SceneParameters.h"

#include "../../AssetsLoad/StartUpLoad/StartUpLoad.h"

class ModeSelect :public IScene
{
public:
	ModeSelect(SceneParameters& l_sceneParameters, StartUpLoad& l_load);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	SceneParameters* sceneParameters_{ nullptr };
	StartUpLoad* load_{ nullptr };

	ModeSelectCamera camera_;

	ModeID m_modeID;

	InputState input_;
	bool m_isEnd;	//èIóπÉtÉâÉO
};

#endif