#ifndef _COLLISION_TRIANGLE_H_
#define _COLLISION_TRIANGLE_H_

#include <DxLib.h>

//衝突判定用の三角形クラス
class CollisionTriangle
{
public:
	//コンストラクタ
	CollisionTriangle(const VECTOR& p1, const VECTOR& p2, const VECTOR& p3);

	//三角形の内側に座標があるか
	bool is_inside(const VECTOR& point)const;

	//三角形の辺と球体の衝突判定
	bool collide_edge_and_sphere(const VECTOR& center, float radius, VECTOR*result = nullptr);

private:
	//三角形の頂点
	VECTOR points_[3];
};

#endif