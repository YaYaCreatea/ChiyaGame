#ifndef _CHARACTER_DECISION_H_
#define _CHARACTER_DECISION_H_

#include "../../Utility/Vector2/Vector2.h"
#include "../../Utility/Input/InputState.h"

#include "CharacterSelecter.h"

class CharacterDecision
{
public:
	CharacterDecision(CharacterSelecter& l_selecter);

	void Initialize();

	void Decision_Duel(float deltaTime);

	void Decision_Four(float deltaTime);

	void DrawDecisionICO_Duel()const;

	void DrawDecisionICO_Four()const;

private:

	bool ChiyaSelectArea(Vector2 l_icoPosition)const;
	bool RizeSelectArea(Vector2 l_icoPosition)const;
	bool SyaroSelectArea(Vector2 l_icoPosition)const;
	bool CocoaSelectArea(Vector2 l_icoPosition)const;

private:
	CharacterSelecter* charaSelecter_{ nullptr };

	InputState input1P_;
	InputState input2P_;
	InputState input3P_;
	InputState input4P_;

	Vector2 m_1Pposition;
	Vector2 m_2Pposition;
	Vector2 m_3Pposition;
	Vector2 m_4Pposition;

	float m_icoSpeed;
};

#endif