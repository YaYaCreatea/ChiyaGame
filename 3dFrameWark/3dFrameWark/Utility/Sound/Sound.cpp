#include "Sound.h"
#include <DxLib.h>

//BGMハンドル
std::unordered_map<int, int> Sound::bgm_map_;

//再生中のBGM
int Sound::current_bgm_{ -1 };

//SEハンドル
std::unordered_map<int, int> Sound::se_map_;

//初期化
void Sound::initialize()
{
	stop_bgm();
	InitSoundMem();
	bgm_map_.clear();
	se_map_.clear();
	current_bgm_ = -1;
}

//BGMの読み込み
void Sound::load_bgm(int id, const std::string & file_name)
{
	bgm_map_[id] = LoadSoundMem(file_name.c_str(), 1);
}

//BGM再生
void Sound::play_bgm(int id)
{
	//現在再生中のBGMを停止
	stop_bgm();
	//バックグラウンド再生、ループ再生
	current_bgm_ = bgm_map_[id];
	PlaySoundMem(current_bgm_, DX_PLAYTYPE_BACK | DX_PLAYTYPE_LOOP);
}

//BGM停止
void Sound::stop_bgm()
{
	if (current_bgm_ == -1)return;
	StopSoundMem(current_bgm_);
	current_bgm_ = -1;
}

//BGM削除
void Sound::delete_bgm(int id)
{
	DeleteSoundMem(bgm_map_[id]);
	bgm_map_.erase(id);
}

//SEの読み込み
void Sound::load_se(int id, const std::string & file_name)
{
	se_map_[id] = LoadSoundMem(file_name.c_str());
}

//SE再生
void Sound::play_se(int id)
{
	//バックグラウンド再生
	PlaySoundMem(se_map_[id], DX_PLAYTYPE_BACK);
}

//SE削除
void Sound::delete_se(int id)
{
	DeleteSoundMem(se_map_[id]);
	se_map_.erase(id);
}

//終了
void Sound::finalize()
{
	initialize();
}
