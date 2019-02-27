#ifndef _WINNER_CHARACTER_H_
#define _WINNER_CHARACTER_H_

#include "../../CharacterID/CharacterID.h"

class WinnerCharacter
{
public:
	WinnerCharacter();
	~WinnerCharacter();
	void initialize();

	void Set_Winner(CharaID l_charaID);
	CharaID Get_Winner()const;

private:
	CharaID m_winner;
};

#endif