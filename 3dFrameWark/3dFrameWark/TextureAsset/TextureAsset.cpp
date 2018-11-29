#include "TextureAsset.h"
#include <DxLib.h>

//デストラクタ
TextureAsset::~TextureAsset()
{
	clear();
}

//読み込み
bool TextureAsset::load(int id, const std::string & file_name)
{
	erase(id);
	textures_[id] = LoadGraph(file_name.c_str());
	return textures_[id] != -1;
}

//削除
void TextureAsset::erase(int id)
{
	if (textures_.count(id) > 0)
	{
		DeleteGraph(textures_[id]);
		textures_.erase(id);
	}
}

//消去
void TextureAsset::clear()
{
	for (const auto texture : textures_)
	{
		DeleteGraph(texture.second);
	}
	textures_.clear();
}

//ハンドルの取得
int TextureAsset::operator[](int id) const
{
	return textures_.at(id);
}
