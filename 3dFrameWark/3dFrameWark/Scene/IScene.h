#ifndef _I_SCENE_H_
#define _I_SCENE_H_

enum class SceneID;

#include <DxLib.h>

class IScene
{
public:
	//仮想デストラクタ
	virtual ~IScene() {}

	//開始
	virtual void start() = 0;

	//更新
	virtual void update(float delta_time) = 0;

	//描画
	virtual void draw()const = 0;

	//終了しているか
	virtual bool is_end()const = 0;

	//次のシーンを返す
	virtual SceneID next()const = 0;

	//終了
	virtual void end() = 0;
};

#endif