#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_

#include <Dxlib.h>
#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Matrix/Matrix.h"

class BoundingSphere
{
public:
	//�R���X�g���N�^
	BoundingSphere() = default;

	//�R���X�g���N�^
	BoundingSphere(const Vector3& center, float radius);

	//���s�ړ�
	BoundingSphere translate(const Vector3& position)const;

	//���W�ϊ�
	BoundingSphere transform(const Matrix& matrix)const;

	//�d�Ȃ��Ă��邩
	bool intersects(const BoundingSphere& other)const;

	//�f�o�b�O�\��
	void draw(const Matrix & matrix) const;

public:
	Vector3 m_center{ 0.0f,0.0f,0.0f };
	float m_radius{ 0.0f };
};

#endif