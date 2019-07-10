#include "Effect.h"
#include <EffekseerForDXLib.h>

//�o�C���h���̃e�N�X�`��
int Effect::efk_{ -1 };
//�e�N�X�`���A�Z�b�g
EffectAsset Effect::effect_;

// ������
void Effect::initialize()
{
	finalize();
}

// �I������
void Effect::finalize()
{
	effect_.clear();
	efk_ = -1;
}

// �ǂݍ���
bool Effect::load(int id, const std::string & file_name)
{
	return effect_.load(id, file_name);
}

// �w��G�t�F�N�g�̍폜
void Effect::erase(int id)
{
	efk_ = (efk_ == effect_[id]) ? -1 : efk_;
	effect_.erase(id);
}

void Effect::update()
{
}

// �A���t�@�l�t�F�[�h
void Effect::alphaFead(float l_alpha)
{
	MV1SetOpacityRate(efk_, l_alpha / 60.0f);
}

void Effect::play(int id,const Vector3 & position, float pitch, float yaw, float roll)
{
}

// �o�C���h
void Effect::bind(int id)
{
	efk_ = effect_[id];
}

// �`��
void Effect::draw()
{
	//DrawEffekseer3D();

	MV1DrawModel(efk_);
}

// ���s�ړ�
void Effect::transform(const Vector3& l_position,const Matrix & l_matrix, float l_pitch, float l_yaw)
{
	MV1SetMatrix(
		efk_,
		Matrix(l_matrix*
			Matrix::CreateFromAxisAngle(l_matrix.Forward(), l_pitch)*
			Matrix::CreateFromAxisAngle(Vector3::Up, l_yaw)).Translation(l_position));
}

// �G�t�F�N�g�̎擾
int Effect::get_effect(int id)
{
	return effect_[id];
}
