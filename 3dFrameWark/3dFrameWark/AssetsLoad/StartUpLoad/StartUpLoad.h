#ifndef _START_UP_LOAD_H_
#define _START_UP_LOAD_H_

class StartUpLoad
{
public:
	StartUpLoad();
	~StartUpLoad();
	void Load();
	void UnLoad();
	int get_loadNum()const;

private:
	int m_loadNum;
};

#endif