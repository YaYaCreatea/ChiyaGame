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

	////Effekseerを初期化する。
	////引数には画面に表示する最大パーティクル数を設定する。
	//if (Effkseer_Init(8000) == -1)
	//{
	//	DxLib_End();
	//	return -1;
	//}

	//// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	//// Effekseerを使用する場合は必ず設定する。
	//SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	//// DXライブラリのデバイスロストした時のコールバックを設定する。
	//// ウインドウとフルスクリーンの切り替えが発生する場合は必ず実行する。
	//Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	//GetEffekseer3DManager()->SetCoordinateSystem(Effekseer::CoordinateSystem::LH);

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//SetBackgroundColor(0,255,0);

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

	// Effekseerを終了する。
	//Effkseer_End();

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
