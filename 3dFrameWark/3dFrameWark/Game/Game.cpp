#include "Game.h"
#include "DxLib.h"

Game::Game(int widht, int height, bool full_screen)
	:window_width_(widht), window_height_(height),
	is_full_screen_(full_screen)
{
}

int Game::run()
{
	//�E�B���h�E�T�C�Y�̐ݒ�
	SetWindowSize(window_width_, window_height_);

	//�t���X�N���[�����[�h���̉𑜓x��ݒ�
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);

	//�O���t�B�b�N���[�h�̐ݒ�
	SetGraphMode(window_width_, window_height_, 32);

	//�E�B���h�E���[�h��
	ChangeWindowMode(is_full_screen_ ? FALSE : TRUE);

	// �t���V�[���A���`�G�C���A�X��ݒ肷��
	SetFullSceneAntiAliasingMode(4, 2);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
		return -1;

	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	SetMouseDispFlag(FALSE);

	//�J�n
	start();

	//���C�����[�v(�����L�[�������ꂽ�甲����)
	while (ProcessMessage() == 0 && is_running())
	{
		//�X�V
		update(1.0f);

		//��ʂ̃N���A
		ClearDrawScreen();

		//�`��
		draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//�I��
	end();

	//DX���C�u�����̌�n��
	DxLib_End();

	//����I��
	return 0;
}

void Game::start() {}

void Game::update(float) {}

void Game::draw() {}

void Game::end() {}

bool Game::is_running() const
{
	//�G�X�P�[�v�L�[�ŋ����I��
	return CheckHitKey(KEY_INPUT_ESCAPE) == 0;
}
