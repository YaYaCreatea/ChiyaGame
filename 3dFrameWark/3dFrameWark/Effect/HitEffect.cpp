#include "HitEffect.h"
#include "../assetsID/AssetsID.h"
#include "../Billboard/Billboard.h"

#include "../Utility/MathHelper/MathHelper.h"

/*
	ヒットエフェクト
*/

HitEffect::HitEffect(const Vector3 & l_position)
{
	m_position = l_position;
	m_size = 17.0f;
	m_timer = 20.0f;
}

void HitEffect::update(float deltaTime)
{
	if (m_timer <= 0.0f)
		m_isdead = true;

	// パラメーター更新
	m_size = MathHelper::Clamp(m_size + deltaTime, 17.0f, 20.0f);
	m_timer -= deltaTime;
}

void HitEffect::draw() const
{
	Billboard::bind((int)BillBoardID::Hit);
	Billboard::draw(m_position + Vector3{ 0.0f,10.0f,0.0f }, m_size, 0.5f, 0.5f);
}
