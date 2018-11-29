#ifndef _MODEL_ASSET_H_
#define _MODEL_ASSET_H_

#include <unordered_map>
#include <string>

class ModelAsset
{
public:
	//�R���X�g���N�^
	ModelAsset();

	//�f�X�g���N�^
	~ModelAsset();

	//�ǂݍ���
	bool load(int id, const std::string& file_name);

	//�폜
	void erase(int id);

	//����
	void clear();

	//�n���h���̎擾
	int operator[](int id)const;

	//�R�s�[�֎~
	ModelAsset(const ModelAsset&) = delete;
	ModelAsset&operator=(const ModelAsset&) = delete;

private:
	//���f���f�[�^�}�b�v
	std::unordered_map<int, int> asset_;
};

#endif