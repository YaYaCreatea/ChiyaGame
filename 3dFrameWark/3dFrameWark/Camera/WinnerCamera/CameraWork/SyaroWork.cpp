#include "SyaroWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

SyaroWork::SyaroWork()
{
}

void SyaroWork::WorkInitialize()
{
	m_state = WorkStateSyaro::Work0;
	m_back = 5.0f;
	m_value = 0.0f;
	m_timer = 0.0f;
}

void SyaroWork::WorkUpdate(float deltaTime, const Vector3 & l_syaroPosition, Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	if (m_state == WorkStateSyaro::Work0)
	{
		m_back = MathHelper::Lerp(10.0f, 18.0f, m_timer / 60.0f);
		Vector3& l_backPosition = (l_rotation.Forward().Normalize()* m_back);
		const Vector3& l_upPosition = Vector3{ -4.0f, 18.0f, 0.0f };

		l_position = l_syaroPosition + l_backPosition + l_upPosition;
		l_lookPosition = Vector3{
			l_syaroPosition.x,
			l_syaroPosition.y + 16.0f,
			l_syaroPosition.z };

		if (m_timer >= 120.0f)
		{
			m_state = WorkStateSyaro::Work1;
			m_back = 30.0f;
			m_timer = 0.0f;
			return;
		}

		m_timer += deltaTime;
	}
	else if (m_state == WorkStateSyaro::Work1)
	{
		m_value = MathHelper::Lerp(15.0f, -10.0f, m_timer / 300.0f);
		m_back = MathHelper::Lerp(30.0f, 23.0f, (m_timer - 240.0f) / 60.0f);
		Vector3& l_backPosition = (l_rotation.Forward().Normalize()* m_back);
		Vector3& l_upPosition = Vector3{ m_value, 13.0f, 0.0f };

		l_position = l_syaroPosition + l_backPosition + l_upPosition;
		l_lookPosition = Vector3{
			l_syaroPosition.x,
			l_syaroPosition.y + 14.0f,
			l_syaroPosition.z };

		m_timer += deltaTime;
	}
}
