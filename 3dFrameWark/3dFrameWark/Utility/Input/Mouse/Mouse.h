#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "../../Vector2/Vector2.h"

class Mouse
{
public:
	//�}�E�X�̃{�^��
	static const int Left;
	static const int Right;
	static const int Middle;

	//������
	static void initialize();

	//�X�V
	static void update();

	//�}�E�X�J�[�\���̈ʒu���擾
	static Vector2 get_cursor_point();

	//�}�E�X�J�[�\���̈ʒu��ݒ�
	static void set_cursor_point(const Vector2& point);

	//�}�E�X�J�[�\���̕\��
	static void show_cursor();

	//�}�E�X�J�[�\���̔�\��
	static void hide_cursor();

	//�{�^����������Ă��邩
	static bool state(int button);

	//�{�^���������ꂽ��
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