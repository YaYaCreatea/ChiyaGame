#include "EffectModel.h"
#include <DxLib.h>

EffectModel::EffectModel(const std::string& file_name)
{
	m_model = MV1LoadModel(file_name.c_str());
}

void EffectModel::update(float l_alpha)
{
	if (l_alpha <= 0.0f)
		MV1DeleteModel(m_model);

	MV1SetOpacityRate(m_model, l_alpha / 60.0f);
}

void EffectModel::draw() const
{
	MV1DrawModel(m_model);
}

void EffectModel::transform(const Vector3 & l_position, const Matrix & l_matrix, float l_pitch, float l_yaw)
{
	MV1SetMatrix(
		m_model,
		Matrix(l_matrix*
			Matrix::CreateFromAxisAngle(l_matrix.Forward(), l_pitch)*
			Matrix::CreateFromAxisAngle(Vector3::Up, l_yaw)).Translation(l_position));
}

void EffectModel::transform(const Vector3 & l_position, const Matrix & l_matrix, const Vector3 & l_size)
{
	MV1SetMatrix(
		m_model,
		Matrix(l_matrix*Matrix::CreateScale(l_size)).Translation(l_position));
}