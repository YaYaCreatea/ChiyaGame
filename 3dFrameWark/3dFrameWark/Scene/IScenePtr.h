#ifndef _I_SCENE_PTR_H_
#define _I_SCENE_PTR_H_

#include <memory>

//�V�[���|�C���^
class IScene;
using IScenePtr = std::shared_ptr<IScene>;

//�V�[���̍쐬
template<class T, class... Args>
inline IScenePtr new_scene(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif