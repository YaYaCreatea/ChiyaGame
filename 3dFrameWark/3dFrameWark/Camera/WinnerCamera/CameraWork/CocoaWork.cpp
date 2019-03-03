#include "CocoaWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

CocoaWork::CocoaWork()
{
}

void CocoaWork::WorkInitialize()
{
	m_state = WorkStateCocoa::Work0;
	m_back = 5.0f;
	m_value = 0.0f;
	m_timer = 0.0f;
}

void CocoaWork::WorkUpdate(float deltaTime, const Vector3 & l_chiyaPosition, Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	if (m_state == WorkStateCocoa::Work0)
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
			m_state = WorkStateCocoa::Work1;
			m_back = 30.0f;
			m_timer = 0.0f;
			return;
		}

		m_timer += deltaTime;
	}
	else if (m_state == WorkStateCocoa::Work1)
	{
		m_value = MathHelper::Lerp(-15.0f, 5.0f, m_timer / 360.0f);
		m_back = MathHelper::Lerp(30.0f, 20.0f, (m_timer - 120.0f) / 120.0f);
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
