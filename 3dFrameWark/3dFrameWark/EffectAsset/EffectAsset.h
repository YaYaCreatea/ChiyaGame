#ifndef _EFFECT_ASSET_H_
#define _EFFECT_ASSET_H_

#include <unordered_map>
#include <string>

class EffectAsset
{
public:
	//�R���X�g���N�^
	EffectAsset();

	//�f�X�g���N�^
	~EffectAsset();

	//�ǂݍ���
	bool load(int id, const std::string& file_name);

	//�폜
	void erase(int id);

	//����
	void clear();

	//�n���h���̎擾
	int operator[](int id)const;

	//�R�s�[�֎~
	EffectAsset(const EffectAsset&) = delete;
	EffectAsset&operator=(const EffectAsset&) = delete;

private:
	//�G�t�F�N�g�f�[�^�}�b�v
	std::unordered_map<int, int> effect_;
};

#endif