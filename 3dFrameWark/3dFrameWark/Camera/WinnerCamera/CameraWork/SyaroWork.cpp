#include "SyaroWork.h"
#include "../../../Utility/MathHelper/MathHelper.h"

SyaroWork::SyaroWork()
{
}

void SyaroWork::WorkInitialize()
{
	m_state = WorkStateSyaro::Work0;
	m_value0 = 0.0f;
	m_value1 = 0.0f;
	m_value2 = 0.0f;
	m_value3 = 0.0f;
	m_timer = 0.0f;
}

void SyaroWork::WorkUpdate(float deltaTime, const Vector3 & l_syaroPosition, Vector3 & l_position, Vector3 & l_lookPosition, Matrix & l_rotation)
{
	// カット0
	if (m_state == WorkStateSyaro::Work0)
	{
		m_value0 = 15.0f;
		m_value1 = 4.0f;
		m_value2 = 18.0f;
		m_value3 = 16.0f;

		if (m_timer >= 50.0f)
		{
			m_state = WorkStateSyaro::Work1;
			return;
		}
	}

	// カット1
	else if (m_state == WorkStateSyaro::Work1)
	{
		m_value0 = MathHelper::Lerp(15.0f, 22.0f, (m_timer - 50.0f) / 10.0f);
		m_value1 = MathHelper::Lerp(4.0f, 0.0f, (m_timer - 50.0f) / 10.0f);
		m_value2 = 18.0f;
		m_value3 = 16.0f;

		if (m_timer >= 85.0f)
		{
			m_state = WorkStateSyaro::Work2;
			m_timer = 0.0f;
			return;
		}
	}

	// カット2
	else if (m_state == WorkStateSyaro::Work2)
	{
		m_value0 = 5.0f;
		m_value1 = 4.0f;
		m_value2 = 18.0f;
		m_value3 = 16.0f;

		if (m_timer >= 30.0f)
		{
			m_state = WorkStateSyaro::Work3;
			return;
		}
	}

	// カット3
	else if (m_state == WorkStateSyaro::Work3)
	{
		m_value0 = MathHelper::Lerp(5.0f, 30.0f, (m_timer - 30.0f) / 20.0f);
		m_value1 = 4.0f;
		m_value2 = MathHelper::Lerp(18.0f, 10.0f, (m_timer - 30.0f) / 20.0f);
		m_value3 = MathHelper::Lerp(16.0f, 12.0f, (m_timer - 30.0f) / 20.0f);
	}

	// 移動制御
	Vector3 l_forwardPos = (l_rotation.Forward().Normalize()* m_value0);
	Vector3 l_up_rightPos = Vector3{ m_value1, m_value2, 0.0f };
	l_position = l_syaroPosition + l_forwardPos + l_up_rightPos;

	// 視点設定
	l_lookPosition = Vector3{
		l_syaroPosition.x,
		l_syaroPosition.y + m_value3,
		l_syaroPosition.z };

	// タイマーの更新
	m_timer += deltaTime;
}
