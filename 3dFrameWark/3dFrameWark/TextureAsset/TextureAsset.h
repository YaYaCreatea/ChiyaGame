#ifndef _TEXTURE_ASSET_H_
#define _TEXTURE_ASSET_H_

#include <string>
#include <unordered_map>

//�e�N�X�`���A�Z�b�g
class TextureAsset
{
public:
	//�R���X�g���N�^
	TextureAsset() = default;

	//�f�X�g���N�^
	~TextureAsset();

	//�ǂݍ���
	bool load(int id, const std::string& file_name);

	//�폜
	void erase(int id);

	//����
	void clear();

	//�n���h���̎擾
	int operator[](int id)const;

	//�R�s�[�֎~
	TextureAsset(const TextureAsset&) = delete;
	TextureAsset&operator=(const TextureAsset&) = delete;

private:
	//�e�N�X�`���f�[�^�}�b�v
	std::unordered_map<int, int> textures_;
};

#endif