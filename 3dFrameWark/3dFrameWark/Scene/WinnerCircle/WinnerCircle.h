#ifndef _WINNER_CIRCLE_H_
#define _WINNER_CIRCLE_H_

#include "../../Scene/IScene.h"
#include "../SceneID.h"

#include "../../World/World.h"

#include "../../AssetsLoad/PlayLoad/PlayLoad.h"
#include "../Fead/FeadInOut.h"
#include "WinnerCharacter.h"

#include "../../Utility/Input/InputState.h"
#include "../../Utility/Vector2/Vector2.h"

class WinnerCircle :public IScene
{
public:
	WinnerCircle(PlayLoad& l_load, WinnerCharacter& l_winner);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	PlayLoad* load_{ nullptr };
	WinnerCharacter* winner_{ nullptr };

	World world_;
	FeadInOut fead_;
	InputState input_;

	bool m_isEnd;
	bool m_isNext;
};

#endif