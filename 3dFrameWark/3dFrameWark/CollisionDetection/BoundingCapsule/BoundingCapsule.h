#ifndef _BOUNDING_CAPSULE_H_
#define _BOUNDING_CAPSULE_H_

#include <Dxlib.h>
#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Matrix/Matrix.h"

class BoundingCapsule
{
public:
	//コンストラクタ
	BoundingCapsule() = default;

	//コンストラクタ
	BoundingCapsule(const Vector3& v1, float height, float radius);

	//コンストラクタ
	BoundingCapsule(const Vector3& v1, const Vector3& v2, float radius);

	//平行移動
	BoundingCapsule translate(const Vector3& position)const;

	//座標変換
	BoundingCapsule transform(const Matrix& matrix)const;

	//重なっているか
	bool intersects(const BoundingCapsule& other)const;

	Vector3 PushedBack_CapsuleCapsule(const BoundingCapsule& other) const;

	//デバッグ表示
	void draw(const Matrix & matrix) const;

public:
	Vector3 m_under_position{ 0.0f,0.0f,0.0f };
	Vector3 m_height_position{ 0.0f,0.0f,0.0f };
	float m_radius{ 0.0f };
};

#endif