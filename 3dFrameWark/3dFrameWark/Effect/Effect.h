#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "../EffectAsset/EffectAsset.h"
#include "../Utility/Vector3/Vector3.h"
#include <string>

//ビルボード
class Effect
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

	static void update();

	static void play(int id,const Vector3& position, float pitch = 0.0f, float yaw = 0.0f, float roll = 0.0f);

	//バインド
	static void bind(int id);

	//描画
	static void draw();

private:
	//バインド中のエフェクト
	static int efk_;
	//エフェクトアセット
	static EffectAsset effect_;
};

#endif