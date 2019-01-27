#ifndef _I_SCENE_H_
#define _I_SCENE_H_

enum class SceneID;

#include <DxLib.h>

class IScene
{
public:
	//���z�f�X�g���N�^
	virtual ~IScene() {}

	//�J�n
	virtual void start() = 0;

	//�X�V
	virtual void update(float delta_time) = 0;

	//�`��
	virtual void draw()const = 0;

	//�I�����Ă��邩
	virtual bool is_end()const = 0;

	//���̃V�[����Ԃ�
	virtual SceneID next()const = 0;

	//�I��
	virtual void end() = 0;
};

#endif