#ifndef _GAME_PAD_H_
#define _GAME_PAD_H_

class GamePad
{
public:
	//ゲームパッドのボタン
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

	//初期化
	static void initialize();

	//更新
	static void update();

	//ボタンが押されているか
	static bool state(int button);

	//ボタンが押されてたか
	static bool trigger(int button);

	//ボタンが離されたか
	static bool release(int button);

	//終了処理
	static void finalize();

private:
	//今回の入力状態
	static int current_state_;

	//前回の入力状態
	static int previos_state_;
};

#endif