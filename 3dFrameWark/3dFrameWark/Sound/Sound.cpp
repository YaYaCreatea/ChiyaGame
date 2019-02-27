#include "Sound.h"
#include <DxLib.h>

//BGM�n���h��
std::unordered_map<int, int> Sound::bgm_map_;

//�Đ�����BGM
int Sound::current_bgm_{ -1 };

//SE�n���h��
std::unordered_map<int, int> Sound::se_map_;

//������
void Sound::initialize()
{
	stop_bgm();
	InitSoundMem();
	bgm_map_.clear();
	se_map_.clear();
	current_bgm_ = -1;
}

//BGM�̓ǂݍ���
void Sound::load_bgm(int id, const std::string & file_name)
{
	bgm_map_[id] = LoadSoundMem(file_name.c_str(), 1);
}

//BGM�Đ�
void Sound::play_bgm(int id)
{
	//���ݍĐ�����BGM���~
	stop_bgm();
	//�o�b�N�O���E���h�Đ��A���[�v�Đ�
	current_bgm_ = bgm_map_[id];
	PlaySoundMem(current_bgm_, DX_PLAYTYPE_BACK | DX_PLAYTYPE_LOOP);
}

//BGM��~
void Sound::stop_bgm()
{
	if (current_bgm_ == -1)return;
	StopSoundMem(current_bgm_);
	current_bgm_ = -1;
}

//BGM�폜
void Sound::delete_bgm(int id)
{
	DeleteSoundMem(bgm_map_[id]);
	bgm_map_.erase(id);
}

//SE�̓ǂݍ���
void Sound::load_se(int id, const std::string & file_name)
{
	se_map_[id] = LoadSoundMem(file_name.c_str());
}

//SE�Đ�
void Sound::play_se(int id)
{
	//�o�b�N�O���E���h�Đ�
	PlaySoundMem(se_map_[id], DX_PLAYTYPE_BACK);
}

//SE�폜
void Sound::delete_se(int id)
{
	DeleteSoundMem(se_map_[id]);
	se_map_.erase(id);
}

//�I��
void Sound::finalize()
{
	initialize();
}
