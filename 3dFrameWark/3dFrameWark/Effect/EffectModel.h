#ifndef _EFFECT_MODEL_H_
#define _EFFECT_MODEL_H_

#include "Effect.h"

class EffectModel
{
public:
	EffectModel(const std::string& file_name);

	void update(float l_alpha);

	void draw()const;

	void transform(const Vector3& l_position, const Matrix& l_matrix, float l_pitch, float l_yaw);

private:
	int m_model;
};

#endif