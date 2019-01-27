#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "../Scene/IScenePtr.h"
#include <map>

enum class SceneID;

class SceneManager
{
public:
	SceneManager();
	//�J�n
	void initialize();
	//�X�V
	void update(float deltaTime);
	//�`��
	void draw()const;
	//�I��
	void end();
	//�V�[���ǉ�
	void Add_Scece(SceneID name, const IScenePtr& scene);
	//�V�[���̕ύX
	void Change_Scene(SceneID name);
	//�R�s�[�֎~
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator =(const SceneManager& other) = delete;

private:
	std::map<SceneID, IScenePtr> scenes_;
	IScenePtr currentScene_;
};

#endif