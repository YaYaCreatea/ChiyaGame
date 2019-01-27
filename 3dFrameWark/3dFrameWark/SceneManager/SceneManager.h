#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "../Scene/IScenePtr.h"
#include <map>

enum class SceneID;

class SceneManager
{
public:
	SceneManager();
	//開始
	void initialize();
	//更新
	void update(float deltaTime);
	//描画
	void draw()const;
	//終了
	void end();
	//シーン追加
	void Add_Scece(SceneID name, const IScenePtr& scene);
	//シーンの変更
	void Change_Scene(SceneID name);
	//コピー禁止
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator =(const SceneManager& other) = delete;

private:
	std::map<SceneID, IScenePtr> scenes_;
	IScenePtr currentScene_;
};

#endif