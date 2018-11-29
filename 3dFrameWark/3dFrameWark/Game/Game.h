#ifndef _GAME_H_
#define _GAME_H_

//main�֐����G���g���|�C���g�ɂ���
#pragma comment(linker,"/entry:mainCRTStartup")

class Game
{
public:
	//�R���X�g���N�^
	Game() = default;

	//�R���X�g���N�^
	Game(int width, int height, bool full_screen);

	//���s
	int run();

	//�R�s�[�֎~
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;

private:
	//�J�n
	virtual void start();
	//�X�V
	virtual void update(float);
	//�`��
	virtual void draw();
	//�I��
	virtual void end();
	//���s����?
	virtual bool is_running()const;

private:
	int window_width_{ 640 };		//�E�B���h�E�̕�
	int window_height_{ 480 };		//�E�B���h�E�̍���
	bool is_full_screen_{ false };	//�t���X�N���[�����[�h
};

#endif