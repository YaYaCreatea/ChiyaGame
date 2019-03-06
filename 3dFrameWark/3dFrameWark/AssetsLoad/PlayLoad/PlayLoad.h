#ifndef _PLAY_LOAD_H_
#define _PLAY_LOAD_H_

class PlayLoad
{
public:
	//コンストラクタ
	PlayLoad();

	//デストラクタ
	~PlayLoad();

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