#ifndef _PLAY_LOAD_H_
#define _PLAY_LOAD_H_

class PlayLoad
{
public:
	PlayLoad();
	~PlayLoad();
	void Load();
	void UnLoad();
	int get_loadNum()const;

private:
	int m_loadNum;
};

#endif