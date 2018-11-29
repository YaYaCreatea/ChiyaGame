#include "StaticMesh.h"
#include <DxLib.h>

//�o�C���h���̃��f��
int StaticMesh::model_{ -1 };
//���f���̃��[���h�ϊ��s��
Matrix StaticMesh::world_matrix_{ Matrix::Identity };
//���f���A�Z�b�g
ModelAsset StaticMesh::asset_;

//������
void StaticMesh::initialize()
{
	finalize();
}

//�I������
void StaticMesh::finalize()
{
	asset_.clear();
	model_ = -1;
	world_matrix_ = Matrix::Identity;
}

//�ǂݍ���
bool StaticMesh::load(int id, const std::string & file_name)
{
	return asset_.load(id, file_name);
}

//�폜
void StaticMesh::erase(int id)
{
	model_ = (model_ == asset_[id]) ? -1 : model_;
	asset_.erase(id);
}

//���b�V���̃o�C���h
void StaticMesh::bind(int id)
{
	model_ = asset_[id];
}

//�`��
void StaticMesh::draw()
{
	MV1SetMatrix(model_, world_matrix_);
	MV1DrawModel(model_);
}

//���[���h�ϊ��s����v�Z����
void StaticMesh::transform(const Matrix & world)
{
	world_matrix_ = world;
}
