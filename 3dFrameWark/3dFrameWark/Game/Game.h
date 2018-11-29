#ifndef _GAME_H_
#define _GAME_H_

//main関数をエントリポイントにする
#pragma comment(linker,"/entry:mainCRTStartup")

class Game
{
public:
	//コンストラクタ
	Game() = default;

	//コンストラクタ
	Game(int width, int height, bool full_screen);

	//実行
	int run();

	//コピー禁止
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;

private:
	//開始
	virtual void start();
	//更新
	virtual void update(float);
	//描画
	virtual void draw();
	//終了
	virtual void end();
	//実行中か?
	virtual bool is_running()const;

private:
	int window_width_{ 640 };		//ウィンドウの幅
	int window_height_{ 480 };		//ウィンドウの高さ
	bool is_full_screen_{ false };	//フルスクリーンモード
};

#endif