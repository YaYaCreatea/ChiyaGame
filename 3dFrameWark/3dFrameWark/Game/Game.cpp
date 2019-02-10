#include "Game.h"
#include "DxLib.h"
#include <EffekseerForDXLib.h>

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

	////Effekseer������������B
	////�����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	//if (Effkseer_Init(8000) == -1)
	//{
	//	DxLib_End();
	//	return -1;
	//}

	//// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	//// Effekseer���g�p����ꍇ�͕K���ݒ肷��B
	//SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	//// DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
	//// �E�C���h�E�ƃt���X�N���[���̐؂�ւ�����������ꍇ�͕K�����s����B
	//Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	//GetEffekseer3DManager()->SetCoordinateSystem(Effekseer::CoordinateSystem::LH);

	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//SetBackgroundColor(0,255,0);

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

	// Effekseer���I������B
	//Effkseer_End();

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
