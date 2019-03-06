#ifndef _START_UP_LOAD_H_
#define _START_UP_LOAD_H_

class StartUpLoad
{
public:
	//コンストラクタ
	StartUpLoad();

	//デストラクタ
	~StartUpLoad();

	//アセット読み込み
	void Load();

	//アセットアンロード
	void UnLoad();

	//読み込みアセット数取得
	int get_loadNum()const;

private:
	int m_loadNum;
};

#endif