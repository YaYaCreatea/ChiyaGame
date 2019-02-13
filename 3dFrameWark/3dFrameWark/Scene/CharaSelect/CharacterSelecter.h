#ifndef _CHARACTER_SELECTER_H_
#define _CHARACTER_SELECTER_H_

enum class CharaID
{
	None,
	Chiya,
	Rize,
	Syaro,
	Cocoa,
};

class CharacterSelecter
{
public:
	CharacterSelecter();
	~CharacterSelecter();
	void initialize();

	void Set_1PChara(CharaID l_1P);
	CharaID Get_1PChara()const;

	void Set_2PChara(CharaID l_2P);
	CharaID Get_2PChara()const;

	void Set_3PChara(CharaID l_3P);
	CharaID Get_3PChara()const;

	void Set_4PChara(CharaID l_4P);
	CharaID Get_4PChara()const;

private:
	CharaID m_1P;
	CharaID m_2P;
	CharaID m_3P;
	CharaID m_4P;
};

#endif