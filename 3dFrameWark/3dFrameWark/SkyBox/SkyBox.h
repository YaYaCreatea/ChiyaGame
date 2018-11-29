#ifndef _SKY_BOX_H_
#define _SKY_BOX_H_

#include "../ModelAsset/ModelAsset.h"
#include <string>

//スカイボックスクラス
class SkyBox
{
public:
	//初期化
	static void initialize();
	//終了処理
	static void finalize();
	//読み込み
	static bool load(int id, const std::string& file_name);
	//削除
	static void erase(int id);
	//メッシュのバインド
	static void bind(int id);
	//描画
	static void draw();

private:
	//バインド中のモデル
	static int model_;
	//モデルのアセット
	static ModelAsset asset_;
};

#endif