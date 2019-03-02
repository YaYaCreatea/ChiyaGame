#ifndef _EFFECT_MODEL_H_
#define _EFFECT_MODEL_H_

#include <string>
#include "../Utility/Vector3/Vector3.h"
#include "../Utility/Matrix/Matrix.h"

class EffectModel
{
public:
	EffectModel(const std::string& file_name);

	void update(float l_alpha);

	void draw()const;

	void transform(const Vector3& l_position, const Matrix& l_matrix, float l_pitch = 0.0f, float l_yaw = 0.0f);

	void transform(const Vector3& l_position, const Matrix& l_matrix, const Vector3& l_size);

private:
	int m_model;
};

#endif