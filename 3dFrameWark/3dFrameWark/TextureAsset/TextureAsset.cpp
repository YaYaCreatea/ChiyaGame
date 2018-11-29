#include "TextureAsset.h"
#include <DxLib.h>

//�f�X�g���N�^
TextureAsset::~TextureAsset()
{
	clear();
}

//�ǂݍ���
bool TextureAsset::load(int id, const std::string & file_name)
{
	erase(id);
	textures_[id] = LoadGraph(file_name.c_str());
	return textures_[id] != -1;
}

//�폜
void TextureAsset::erase(int id)
{
	if (textures_.count(id) > 0)
	{
		DeleteGraph(textures_[id]);
		textures_.erase(id);
	}
}

//����
void TextureAsset::clear()
{
	for (const auto texture : textures_)
	{
		DeleteGraph(texture.second);
	}
	textures_.clear();
}

//�n���h���̎擾
int TextureAsset::operator[](int id) const
{
	return textures_.at(id);
}
