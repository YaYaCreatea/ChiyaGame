#include "ModelAsset.h"
#include <DxLib.h>

ModelAsset::ModelAsset()
{
}

//�f�X�g���N�^
ModelAsset::~ModelAsset()
{
	clear();
}

//�ǂݍ���
bool ModelAsset::load(int id, const std::string & file_name)
{
	erase(id);
	asset_[id] = MV1LoadModel(file_name.c_str());
	return asset_[id] != -1;
}

//�폜
void ModelAsset::erase(int id)
{
	if (asset_.count(id) > 0)
	{
		MV1DeleteModel(asset_[id]);
		asset_.erase(id);
	}
}

//����
void ModelAsset::clear()
{
	for (const auto model : asset_)
		MV1DeleteModel(model.second);

	asset_.clear();
}

//�n���h���擾
int ModelAsset::operator[](int id) const
{
	return asset_.at(id);
}
