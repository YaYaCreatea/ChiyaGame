#ifndef _GAME_PAD_H_
#define _GAME_PAD_H_

class GamePad
{
public:
	//�Q�[���p�b�h�̃{�^��
	static const int Left;
	static const int Right;
	static const int Up;
	static const int Down;
	static const int A;
	static const int B;
	static const int X;
	static const int Y;
	static const int S;
	static const int D;
	static const int Back;
	static const int Start;

	//������
	static void initialize();

	//�X�V
	static void update();

	//�{�^����������Ă��邩
	static bool state(int button);

	//�{�^����������Ă���
	static bool trigger(int button);

	//�{�^���������ꂽ��
	static bool release(int button);

	//�I������
	static void finalize();

private:
	//����̓��͏��
	static int current_state_;

	//�O��̓��͏��
	static int previos_state_;
};

#endif