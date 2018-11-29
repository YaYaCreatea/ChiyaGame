#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(const Vector3& center, float radius)
	:m_center{ center }, m_radius{ radius }
{
}

BoundingSphere BoundingSphere::translate(const Vector3 & position) const
{
	return{ m_center + position,m_radius };
}

BoundingSphere BoundingSphere::transform(const Matrix & matrix) const
{
	return{
		Vector3::Transform(m_center,matrix),
		m_radius*matrix.Scale().y
	};
}

bool BoundingSphere::intersects(const BoundingSphere & other) const
{
	return HitCheck_Sphere_Sphere(
		m_center, m_radius,
		other.m_center, other.m_radius) == TRUE;
}

void BoundingSphere::draw(const Matrix & matrix) const
{
	DrawSphere3D(Vector3::Transform(m_center, matrix), m_radius*matrix.Scale().y, 10, 1, 1, 0);
}
