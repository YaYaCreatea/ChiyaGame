#include "EffectModel.h"
#include <DxLib.h>

// エフェクト用モデル読み込み
EffectModel::EffectModel(const std::string& file_name)
{
	m_model = MV1LoadModel(file_name.c_str());
}

// 更新
void EffectModel::update(float l_alpha)
{
	if (l_alpha <= 0.0f)
		MV1DeleteModel(m_model);

	MV1SetOpacityRate(m_model, l_alpha / 60.0f);
}

// 描画
void EffectModel::draw() const
{
	MV1DrawModel(m_model);
}

// 平行移動(回転)
void EffectModel::transform(const Vector3 & l_position, const Matrix & l_matrix, float l_pitch, float l_yaw)
{
	MV1SetMatrix(
		m_model,
		Matrix(l_matrix*
			Matrix::CreateFromAxisAngle(l_matrix.Forward(), l_pitch)*
			Matrix::CreateFromAxisAngle(Vector3::Up, l_yaw)).Translation(l_position));
}

// 平行移動(スケール)
void EffectModel::transform(const Vector3 & l_position, const Matrix & l_matrix, const Vector3 & l_size)
{
	MV1SetMatrix(
		m_model,
		Matrix(l_matrix*Matrix::CreateScale(l_size)).Translation(l_position));
}