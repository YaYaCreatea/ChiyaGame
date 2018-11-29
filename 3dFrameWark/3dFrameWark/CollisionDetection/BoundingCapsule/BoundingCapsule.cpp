#include "BoundingCapsule.h"

BoundingCapsule::BoundingCapsule(const Vector3 & v1, float height, float radius)
	:m_under_position{ v1 },
	m_height_position{ v1 + Vector3{0.0f,height,0.0f} },
	m_radius{ radius }
{
}

BoundingCapsule::BoundingCapsule(const Vector3 & v1, const Vector3 & v2, float radius)
	:m_under_position{ v1 },
	m_height_position{ v2 },
	m_radius{ radius }
{
}

BoundingCapsule BoundingCapsule::translate(const Vector3 & position) const
{
	return{
		m_under_position + position,
		m_height_position + position,
		m_radius
	};
}

BoundingCapsule BoundingCapsule::transform(const Matrix & matrix) const
{
	return{
		Vector3::Transform(m_under_position,matrix),
		Vector3::Transform(m_height_position,matrix),
		m_radius*matrix.Scale().y
	};
}

bool BoundingCapsule::intersects(const BoundingCapsule & other) const
{
	return HitCheck_Capsule_Capsule(
		m_under_position, m_height_position, m_radius,
		other.m_under_position, other.m_height_position, other.m_radius
		) == TRUE;
}

Vector3 BoundingCapsule::PushedBack_CapsuleCapsule(const BoundingCapsule & other) const
{
	Vector3 pushedPosition;

	Vector3 a = m_height_position - m_under_position;
	Vector3 b = other.m_height_position - other.m_under_position;
	Vector3 c = other.m_under_position - m_under_position;

	//Vector3 a = m_height_position - m_under_position;
	//Vector3 b = other.m_height_position - other.m_under_position;
	//Vector3 c = b - a;

	float D = m_radius + other.m_radius;

	Vector3 n = Vector3::Normalize(Vector3::Cross(a, b));
	float L = Vector3::Dot(c, n);

	Vector3 vd;
	if (L > 0)	vd = n * D;
	else		vd = -n * D;

	Vector3 p = m_under_position - (n * L);

	pushedPosition = p + vd;

	return pushedPosition;
}

void BoundingCapsule::draw(const Matrix & matrix) const
{
	DrawCapsule3D(
		Vector3::Transform(m_under_position, matrix),
		Vector3::Transform(m_height_position, matrix),
		m_radius*matrix.Scale().y,
		10, 1, 1, 0);
}
