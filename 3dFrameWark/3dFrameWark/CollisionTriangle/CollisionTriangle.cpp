#include "CollisionTriangle.h"
#include <cmath>

//�R���X�g���N�^
CollisionTriangle::CollisionTriangle(const VECTOR & p1, const VECTOR & p2, const VECTOR & p3)
	:points_{ p1,p2,p3 }
{
}

//�O�p�`�̓����ɍ��W�����邩
bool CollisionTriangle::is_inside(const VECTOR & point) const
{
	//�O�p�`�̏d�S���W���v�Z����
	float w1, w2, w3;
	TriangleBarycenter(points_[0], points_[1], points_[2], point, &w1, &w2, &w3);

	//�d�S���W���O�p�`���ɂ��邩
	return (0.0f <= w1&&w1 <= 1.0f) && (0.0f <= w2&&w2 <= 1.0f) && (0.0f <= w3&&w3 <= 1.0f);
}

//�O�p�`�̕ӂƋ��̂̏Փ˔���
bool CollisionTriangle::collide_edge_and_sphere(const VECTOR & center, float radius, VECTOR * result)
{
	bool is_collided = false;
	VECTOR result_center = center;
	const VECTOR edges[4]{ points_[0],points_[1],points_[2],points_[0] };
	for (int i = 0; i < 3; ++i)
	{
		SEGMENT_POINT_RESULT segment_point_result;
		Segment_Point_Analyse(&edges[i], &edges[i + 1], &result_center, &segment_point_result);
		const auto distance = std::sqrt(segment_point_result.Seg_Point_MinDist_Square);
		if (distance <= radius)
		{
			VECTOR offset = VScale(VNorm(VSub(result_center, segment_point_result.Seg_MinDist_Pos)), radius - distance);
			result_center = VAdd(result_center, offset);
			is_collided = true;
		}
	}
	if (is_collided && (result != nullptr))
	{
		*result = result_center;
	}
	return is_collided;
}

bool CollisionTriangle::collide_edge_and_capsule(const VECTOR & center, const VECTOR & center2, float radius, VECTOR * result)
{
	bool is_collided = false;
	VECTOR result_center = center;
	VECTOR result_center2 = center2;

	const VECTOR edges[4]{ points_[0],points_[1],points_[2],points_[0] };
	for (int i = 0; i < 3; ++i)
	{
		SEGMENT_POINT_RESULT segment_point_result;
		Segment_Point_Analyse(&edges[i], &edges[i + 1], &result_center, &segment_point_result);
		Segment_Point_Analyse(&edges[i], &edges[i + 1], &result_center2, &segment_point_result);
		const auto distance = std::sqrt(segment_point_result.Seg_Point_MinDist_Square);
		if (distance <= radius)
		{
			VECTOR offset = VScale(VNorm(VSub(result_center, segment_point_result.Seg_MinDist_Pos)), radius - distance);
			result_center = VAdd(result_center, offset);
			VECTOR offset2 = VScale(VNorm(VSub(result_center2, segment_point_result.Seg_MinDist_Pos)), radius - distance);
			result_center2 = VAdd(result_center2, offset);
			is_collided = true;
		}
	}
	if (is_collided && (result != nullptr))
	{
		//*result = result_center;
		*result = VAdd(result_center, result_center2);
	}
	return is_collided;
}
