#ifndef _SCENE_PARAMETERS_H_
#define _SCENE_PARAMETERS_H_

#include "SceneID.h"

class SceneParameters
{
public:
	SceneParameters();
	~SceneParameters();
	void initialize();

	void Set_NextSceneID(SceneID l_id);
	SceneID Get_NextSceneID()const;

private:
	SceneID m_nextSceneID;
};

#endif