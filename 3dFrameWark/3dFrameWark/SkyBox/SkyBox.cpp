#include "SkyBox.h"
#include <DxLib.h>

//�o�C���h���̃��f��
int SkyBox::model_{ -1 };
//���f���A�Z�b�g
ModelAsset SkyBox::asset_;

//������
void SkyBox::initialize()
{
	finalize();
}

//�I������
void SkyBox::finalize()
{
	asset_.clear();
	model_ = -1;
}

//�ǂݍ���
bool SkyBox::load(int id, const std::string & file_name)
{
	return asset_.load(id, file_name);
}

//�폜
void SkyBox::erase(int id)
{
	model_ = (model_ == asset_[id]) ? -1 : model_;
	asset_.erase(id);
}

//���b�V���̃o�C���h
void SkyBox::bind(int id)
{
	model_ = asset_[id];
}

//�`��
void SkyBox::draw()
{
	//����ϊ��s��̎擾
	MATRIX view_matrix = GetCameraViewMatrix();

	//����ϊ��s��̕��s�ړ��ʂ��N���A
	MATRIX skybox_matrix = view_matrix;
	skybox_matrix.m[3][0] = 0.0f;
	skybox_matrix.m[3][1] = 0.0f;
	skybox_matrix.m[3][2] = 0.0f;

	//����ϊ��s��̐ݒ�
	SetCameraViewMatrix(skybox_matrix);

	//���C�e�B���O�𖳌��ɂ���
	SetUseLighting(FALSE);

	//Z�o�b�t�@�ɏ������݂��s��Ȃ�
	MV1SetWriteZBuffer(model_, FALSE);

	//���f���̕\��
	MV1DrawModel(model_);

	//����ϊ������ɖ߂�
	SetCameraViewMatrix(view_matrix);

	//���C�e�B���O��L���ɂ���
	SetUseLighting(TRUE);
}
