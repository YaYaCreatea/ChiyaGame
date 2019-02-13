#ifndef _CHARA_SELECT_H_
#define _CHARA_SELECT_H_

#include "../../Scene/IScene.h"

#include "../SceneID.h"

#include "../../Utility/Input/InputState.h"
#include "../../Utility/Vector2/Vector2.h"

#include "../SceneParameters.h"
#include "CharacterSelecter.h"
#include "../../AssetsLoad/StartUpLoad/StartUpLoad.h"

class CharaSelect :public IScene
{
public:
	CharaSelect(CharacterSelecter& l_selecter, SceneParameters& l_sceneParameters, StartUpLoad& l_load);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	bool ChiyaSelectArea(Vector2 l_icoPosition);
	bool RizeSelectArea(Vector2 l_icoPosition);
	bool SyaroSelectArea(Vector2 l_icoPosition);
	bool CocoaSelectArea(Vector2 l_icoPosition);

private:
	CharacterSelecter* charaSelecter_{ nullptr };
	SceneParameters* sceneParameters_{ nullptr };
	StartUpLoad* load_{ nullptr };

	InputState input1P_;
	InputState input2P_;

	bool m_isEnd;	//èIóπÉtÉâÉO

	Vector2 m_1Pposition;
	Vector2 m_2Pposition;
	float m_icoSpeed;
	float m_sceneEndTimer;

};

#endif