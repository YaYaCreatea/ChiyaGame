#include "Game.h"
#include "DxLib.h"

Game::Game(int widht, int height, bool full_screen)
	:window_width_(widht), window_height_(height),
	is_full_screen_(full_screen)
{
}

int Game::run()
{
	//ウィンドウサイズの設定
	SetWindowSize(window_width_, window_height_);

	//フルスクリーンモード時の解像度を設定
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);

	//グラフィックモードの設定
	SetGraphMode(window_width_, window_height_, 32);

	//ウィンドウモードか
	ChangeWindowMode(is_full_screen_ ? FALSE : TRUE);

	// フルシーンアンチエイリアスを設定する
	SetFullSceneAntiAliasingMode(4, 2);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
		return -1;

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	SetMouseDispFlag(FALSE);

	//開始
	start();

	//メインループ(何かキーが押されたら抜ける)
	while (ProcessMessage() == 0 && is_running())
	{
		//更新
		update(1.0f);

		//画面のクリア
		ClearDrawScreen();

		//描画
		draw();

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//終了
	end();

	//DXライブラリの後始末
	DxLib_End();

	//正常終了
	return 0;
}

void Game::start() {}

void Game::update(float) {}

void Game::draw() {}

void Game::end() {}

bool Game::is_running() const
{
	//エスケープキーで強制終了
	return CheckHitKey(KEY_INPUT_ESCAPE) == 0;
}
