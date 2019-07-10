#include "RizeWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

RizeWork::RizeWork()
{
}

void RizeWork::WorkInitialize()
{
	m_state = WorkStateRize::Work0;
	m_value0 = 0.0f;
	m_value1 = 0.0f;
	m_value2 = 0.0f;
	m_value3 = 0.0f;
	m_timer = 0.0f;
}

void RizeWork::WorkUpdate(float deltaTime, const Vector3 & l_chiyaPosition, Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	// カット0
	if (m_state == WorkStateRize::Work0)
	{
		m_value0 = MathHelper::Lerp(40.0f, 22.0f, m_timer / 60.0f);
		m_value1 = 0.0f;
		m_value2 = 15.0f;
		m_value3 = 14.0f;

		if (m_timer >= 80.0f)
		{
			m_state = WorkStateRize::Work1;
			m_timer = 0.0f;
			return;
		}
	}

	// カット1
	else if (m_state == WorkStateRize::Work1)
	{
		m_value0 = 20.0f;
		m_value1 = -6.0f;
		m_value2 = 7.0f;
		m_value3 = 14.0f;

		if (m_timer >= 120.0f)
		{
			m_state = WorkStateRize::Work2;
			m_timer = 0.0f;
			return;
		}
	}

	// カット2
	else if (m_state == WorkStateRize::Work2)
	{
		m_value0 = MathHelper::Lerp(30.0f, 20.0f, m_timer / 360.0f);
		m_value1 = MathHelper::Lerp(-15.0f, -2.0f, m_timer / 360.0f);
		m_value2 = MathHelper::Lerp(13.0f, 18.0f, m_timer / 360.0f);
		m_value3 = 14.0f;
	}

	// 移動制御
	Vector3 l_forwardPos = (l_rotation.Forward().Normalize()* m_value0);
	Vector3 l_up_rightPos = Vector3{ m_value1, m_value2, 0.0f };
	l_position = l_chiyaPosition + l_forwardPos + l_up_rightPos;

	// 視点設定
	l_lookPosition = Vector3{
		l_chiyaPosition.x,
		l_chiyaPosition.y + m_value3,
		l_chiyaPosition.z };

	// タイマーの更新
	m_timer += deltaTime;
}
