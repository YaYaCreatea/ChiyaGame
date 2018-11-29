#ifndef _BOUNDING_SPHERE_H_
#define _BOUNDING_SPHERE_H_

#include <Dxlib.h>
#include "../../Utility/Vector3/Vector3.h"
#include "../../Utility/Matrix/Matrix.h"

class BoundingSphere
{
public:
	//コンストラクタ
	BoundingSphere() = default;

	//コンストラクタ
	BoundingSphere(const Vector3& center, float radius);

	//平行移動
	BoundingSphere translate(const Vector3& position)const;

	//座標変換
	BoundingSphere transform(const Matrix& matrix)const;

	//重なっているか
	bool intersects(const BoundingSphere& other)const;

	//デバッグ表示
	void draw(const Matrix & matrix) const;

public:
	Vector3 m_center{ 0.0f,0.0f,0.0f };
	float m_radius{ 0.0f };
};

#endif