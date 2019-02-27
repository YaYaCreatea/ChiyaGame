#include "SkeletalMesh.h"
#include <DxLib.h>

//�o�C���h���̃��f��
int SkeletalMesh::model_{ -1 };
//�{�[���̃��[�J���ϊ��s��
Matrix SkeletalMesh::local_matrices_[SkeletalMesh::BoneMax];
//�{�[���̃��[���h�ϊ��s��
Matrix SkeletalMesh::world_matrices_[SkeletalMesh::BoneMax];
//���f���A�Z�b�g
ModelAsset SkeletalMesh::asset_;

//������
void SkeletalMesh::initialize()
{
	finalize();
}

//�I������
void SkeletalMesh::finalize()
{
	asset_.clear();
	model_ = -1;
}

//�ǂݍ���
bool SkeletalMesh::load(int id, const std::string & file_name)
{
	return asset_.load(id, file_name);
}

//�폜
void SkeletalMesh::erase(int id)
{
	model_ = (model_ == asset_[id]) ? -1 : model_;
	asset_.erase(id);
}

//���b�V���̃o�C���h
void SkeletalMesh::bind(int id)
{
	model_ = asset_[id];
}

//���[�J���ϊ��s����v�Z
void SkeletalMesh::bind_animation(int motion, float time)
{
	const auto index = MV1AttachAnim(model_, motion);
	MV1SetAttachAnimTime(model_, index, time);
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
	{
		MV1ResetFrameUserLocalMatrix(model_, i);
		local_matrices_[i] = MV1GetFrameLocalMatrix(model_, i);
	}
	MV1DetachAnim(model_, index);
}

//���[�J���ϊ��s����v�Z
void SkeletalMesh::bind_animation(int prev_motion, float prev_time, int motion, float time, float amout)
{
	const auto prev_index = MV1AttachAnim(model_, prev_motion);
	const auto now_index = MV1AttachAnim(model_, motion);

	MV1SetAttachAnimBlendRate(model_, prev_index, 1.0f - amout);
	MV1SetAttachAnimBlendRate(model_, now_index, amout);
	MV1SetAttachAnimTime(model_, prev_index, prev_time);
	MV1SetAttachAnimTime(model_, now_index, time);

	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
	{
		MV1ResetFrameUserLocalMatrix(model_, i);
		local_matrices_[i] = MV1GetFrameLocalMatrix(model_, i);
	}

	MV1DetachAnim(model_, prev_index);
	MV1DetachAnim(model_, now_index);
}

//���[���h�ϊ��s����v�Z
void SkeletalMesh::transform(const Matrix & world)
{
	//���[�J���ϊ��s���ݒ�
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		MV1SetFrameUserLocalMatrix(model_, i, local_matrices_[i]);

	//���[���h�ϊ��s���ݒ�
	MV1SetMatrix(model_, world);

	//���[���h�ϊ��s����擾
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		world_matrices_[i] = MV1GetFrameLocalWorldMatrix(model_, i);
}

//�`��
void SkeletalMesh::draw()
{
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
	{
		MV1ResetFrameUserLocalMatrix(model_, i);
		MV1SetFrameUserLocalWorldMatrix(model_, i, world_matrices_[i]);
	}
	MV1DrawModel(model_);
}

//���[�J���ϊ��s��̎擾
void SkeletalMesh::get_local_matrices(Matrix local_matrices[])
{
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		local_matrices[i] = local_matrices_[i];
}

//���[�J���ϊ��s��̐ݒ�
void SkeletalMesh::set_local_matrices(const Matrix local_matrices[])
{
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		local_matrices_[i] = local_matrices[i];
}

//���[���h�ϊ��s��̎擾
void SkeletalMesh::get_world_matrices(Matrix world_matrices[])
{
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		world_matrices[i] = world_matrices_[i];
}

void SkeletalMesh::get_world_matrices(Matrix world_matrices[], int lkey)
{
	world_matrices[lkey] = world_matrices_[lkey];
}

//���[���h�ϊ��s��̐ݒ�
void SkeletalMesh::set_world_matrices(const Matrix world_matrices[])
{
	for (int i = 0; i < MV1GetFrameNum(model_); ++i)
		world_matrices_[i] = world_matrices[i];
}

void SkeletalMesh::blendshape_animation(float l_attackRate, float l_damageRate)
{
	MV1SetShapeRate(model_, 0, l_attackRate);
	MV1SetShapeRate(model_, 28, l_attackRate);
	MV1SetShapeRate(model_, 30, l_attackRate);

	MV1SetShapeRate(model_, 3, l_damageRate);
	MV1SetShapeRate(model_, 11, l_damageRate);
	MV1SetShapeRate(model_, 27, l_damageRate);
}

//�{�[�����̎擾
int SkeletalMesh::bone_count()
{
	return MV1GetFrameNum(model_);
}

//�I�����Ԃ�Ԃ�
float SkeletalMesh::end_time(int motion)
{
	return MV1GetAnimTotalTime(model_, motion);
}
