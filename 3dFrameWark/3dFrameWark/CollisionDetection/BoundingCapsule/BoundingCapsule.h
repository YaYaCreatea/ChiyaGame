#ifndef _BOUNDING_CAPSULE_H_
#define _BOUNDING_CAPSULE_H_

#include <Dxlib.h>
#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Matrix/Matrix.h"

class BoundingCapsule
{
public:
	//�R���X�g���N�^
	BoundingCapsule() = default;

	//�R���X�g���N�^
	BoundingCapsule(const Vector3& v1, float height, float radius);

	//�R���X�g���N�^
	BoundingCapsule(const Vector3& v1, const Vector3& v2, float radius);

	//���s�ړ�
	BoundingCapsule translate(const Vector3& position)const;

	//���W�ϊ�
	BoundingCapsule transform(const Matrix& matrix)const;

	//�d�Ȃ��Ă��邩
	bool intersects(const BoundingCapsule& other)const;

	Vector3 PushedBack_CapsuleCapsule(const BoundingCapsule& other) const;

	//�f�o�b�O�\��
	void draw(const Matrix & matrix) const;

public:
	Vector3 m_under_position{ 0.0f,0.0f,0.0f };
	Vector3 m_height_position{ 0.0f,0.0f,0.0f };
	float m_radius{ 0.0f };
};

#endif