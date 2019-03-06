#include "CocoaWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

CocoaWork::CocoaWork()
{
}

void CocoaWork::WorkInitialize()
{
	m_state = WorkStateCocoa::Work0;
	m_value0 = 0.0f;
	m_value1 = 0.0f;
	m_value2 = 0.0f;
	m_value3 = 0.0f;
	m_timer = 0.0f;
}

void CocoaWork::WorkUpdate(float deltaTime, const Vector3 & l_chiyaPosition, Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	if (m_state == WorkStateCocoa::Work0)
	{
		m_value0 = MathHelper::Lerp(18.0f, 30.0f, m_timer / 25.0f);
		m_value1 = 0.0f;
		m_value2 = 15.0f;
		m_value3 = 14.0f;

		if (m_timer >= 50.0f)
		{
			m_state = WorkStateCocoa::Work1;
			m_timer = 0.0f;
			return;
		}
	}
	else if (m_state == WorkStateCocoa::Work1)
	{
		m_value0 = 14.0f;
		m_value1 = 0.0f;
		m_value2 = MathHelper::Lerp(20.0f, 35.0f, m_timer / 40.0f);
		m_value3 = 14.0f;

		if (m_timer >= 60.0f)
		{
			m_state = WorkStateCocoa::Work2;
			m_timer = 0.0f;
			return;
		}
	}
	else if (m_state == WorkStateCocoa::Work2)
	{
		m_value0 = MathHelper::Lerp(20.0f, 13.0f, m_timer / 90.0f);
		m_value1 = MathHelper::Lerp(-15.0f, 1.0f, m_timer / 90.0f);
		m_value2 = MathHelper::Lerp(10.0f, 18.0f, m_timer / 90.0f);
		m_value3 = MathHelper::Lerp(10.0f, 16.0f, m_timer / 90.0f);
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
