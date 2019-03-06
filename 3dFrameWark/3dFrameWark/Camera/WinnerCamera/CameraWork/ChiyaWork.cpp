#include "ChiyaWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

ChiyaWork::ChiyaWork()
{
}

void ChiyaWork::WorkInitialize()
{
	m_state = WorkStateChiya::Work0;
	m_value0 = 0.0f;
	m_value1 = 0.0f;
	m_value2 = 0.0f;
	m_value3 = 0.0f;
	m_timer = 0.0f;
}

void ChiyaWork::WorkUpdate(
	float deltaTime,
	const Vector3 & l_chiyaPosition,
	Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	if (m_state == WorkStateChiya::Work0)
	{
		m_value0 = 15.0f;
		m_value1 = 6.0f;
		m_value2 = 17.0f;
		m_value3 = 15.0f;

		if (m_timer >= 60.0f)
		{
			m_state = WorkStateChiya::Work1;
			m_timer = 0.0f;
			return;
		}
	}
	else if (m_state == WorkStateChiya::Work1)
	{
		m_value0 = MathHelper::Lerp(40.0f, 22.0f, m_timer / 60.0f);
		m_value1 = 0.0f;
		m_value2 = 15.0f;
		m_value3 = 14.0f;

		if (m_timer >= 70.0f)
		{
			m_state = WorkStateChiya::Work2;
			m_timer = 0.0f;
			return;
		}		
	}
	else if (m_state == WorkStateChiya::Work2)
	{
		m_value1 = MathHelper::Lerp(-10.0f, -1.0f, m_timer / 300.0f);
		m_value0 = MathHelper::Lerp(30.0f, 14.0f, m_timer / 300.0f);
		m_value2 = MathHelper::Lerp(5.0f, 17.0f, m_timer / 300.0f);
		m_value3 = MathHelper::Lerp(10.0f, 16.0f, m_timer / 300.0f);
	}

	Vector3 l_forwardPos = (l_rotation.Forward().Normalize()* m_value0);
	Vector3 l_up_rightPos = Vector3{ m_value1, m_value2, 0.0f };

	l_position = l_chiyaPosition + l_forwardPos + l_up_rightPos;
	l_lookPosition = Vector3{
		l_chiyaPosition.x,
		l_chiyaPosition.y + m_value3,
		l_chiyaPosition.z };

	m_timer += deltaTime;
}
