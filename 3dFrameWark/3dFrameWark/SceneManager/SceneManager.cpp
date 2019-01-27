#include "SceneManager.h"
#include "../Scene/NullScene/NullScene.h"

SceneManager::SceneManager()
	:currentScene_{ new_scene<NullScene>() }
{
}

void SceneManager::initialize()
{
	end();
	scenes_.clear();
}

void SceneManager::update(float deltaTime)
{
	currentScene_->update(deltaTime);
	if (currentScene_->is_end())
		Change_Scene(currentScene_->next());
}

void SceneManager::draw()const
{
	currentScene_->draw();
}

void SceneManager::end()
{
	currentScene_->end();
	currentScene_ = new_scene<NullScene>();
}

void SceneManager::Add_Scece(SceneID name, const IScenePtr & scene)
{
	scenes_[name] = scene;
}

void SceneManager::Change_Scene(SceneID name)
{
	end();
	currentScene_ = scenes_[name];
	currentScene_->start();
}
