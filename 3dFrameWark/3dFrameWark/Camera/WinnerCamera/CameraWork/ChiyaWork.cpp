#include "ChiyaWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

ChiyaWork::ChiyaWork()
{
}

void ChiyaWork::WorkInitialize()
{
	m_state = WorkStateChiya::Work0;
	m_back = 5.0f;
	m_value = 0.0f;
	m_timer = 0.0f;
}

void ChiyaWork::WorkUpdate(
	float deltaTime,
	const Vector3 & l_chiyaPosition,
	Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	//l_rotation = Matrix::CreateRotationX(m_pitchAngle) * Matrix::CreateRotationY(m_yawAngle);
	//m_rotation.NormalizeRotationMatrix();

	if (m_state == WorkStateChiya::Work0)
	{
		m_back = MathHelper::Lerp(40.0f, 22.0f, m_timer / 60.0f);
		Vector3& l_backPosition = (l_rotation.Forward().Normalize()* m_back);
		const Vector3& l_upPosition = Vector3{ 0.0f, 15.0f, 0.0f };

		l_position = l_chiyaPosition + l_backPosition + l_upPosition;
		l_lookPosition = Vector3{
			l_chiyaPosition.x,
			l_chiyaPosition.y + 14.0f,
			l_chiyaPosition.z };

		if (m_timer >= 120.0f)
		{
			m_state = WorkStateChiya::Work1;
			m_back = 30.0f;
			m_timer = 0.0f;
			return;
		}

		m_timer += deltaTime;
	}
	else if (m_state == WorkStateChiya::Work1)
	{
		m_value = MathHelper::Lerp(15.0f, -10.0f, m_timer / 300.0f);
		m_back = MathHelper::Lerp(30.0f, 23.0f, (m_timer - 240.0f) / 60.0f);
		Vector3& l_backPosition = (l_rotation.Forward().Normalize()* m_back);
		Vector3& l_upPosition = Vector3{ m_value, 13.0f, 0.0f };

		l_position = l_chiyaPosition + l_backPosition + l_upPosition;
		l_lookPosition = Vector3{
			l_chiyaPosition.x,
			l_chiyaPosition.y + 14.0f,
			l_chiyaPosition.z };

		m_timer += deltaTime;
	}
}
