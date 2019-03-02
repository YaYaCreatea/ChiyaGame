#ifndef _CHARA_SELECT_H_
#define _CHARA_SELECT_H_

#include "../../Scene/IScene.h"

#include "../SceneID.h"

#include "../../Utility/Input/InputState.h"
#include "../../Utility/Vector2/Vector2.h"

#include "../SceneParameters.h"
#include "CharacterSelecter.h"
#include "CharacterDecision.h"
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

	void BaseSelectUpdate(float deltaTime);

	void DuelSelect(float deltaTime);
	void FourSelect(float deltaTime);

	void DrawCharacterICO()const;

	bool DuelSelected()const;
	bool FourSelected()const;

private:
	CharacterSelecter* charaSelecter_{ nullptr };
	SceneParameters* sceneParameters_{ nullptr };
	StartUpLoad* load_{ nullptr };

	CharacterDecision charaDecision_;

	bool m_isEnd;	//èIóπÉtÉâÉO
	float m_sceneEndTimer;
};

#endif