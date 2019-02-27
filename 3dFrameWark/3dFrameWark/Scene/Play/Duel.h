#ifndef _DUEL_H_
#define _DUEL_H_

#include "../../Scene/IScene.h"

#include "../../World/World.h"
#include "../../Camera/FrameCamera/FrameCamera.h"

#include "../CharaSelect/CharacterSelecter.h"
#include "../../AssetsLoad/PlayLoad/PlayLoad.h"
#include "../WinnerCircle/WinnerCharacter.h"

class Duel :public IScene
{
public:
	Duel(CharacterSelecter& l_selecter, PlayLoad& l_load, WinnerCharacter& l_winner);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	void EndCheck();

private:
	CharacterSelecter* charaSelecter_{ nullptr };
	PlayLoad* load_{ nullptr };
	WinnerCharacter* winner_{ nullptr };

	World world_;
	FrameCamera frameCamera_;

	bool m_isEnd;	//èIóπÉtÉâÉO

	int m_numChiya;
	int m_numRize;
	int m_numSyaro;
	int m_numCocoa;
};

#endif