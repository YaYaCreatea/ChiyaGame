#include "TitlePerformance.h"

#include <DxLib.h>

#include "../../assetsID/AssetsID.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../Utility/MathHelper/MathHelper.h"

// タイトル演出の初期化
void TitlePerformance::Initialize()
{
	m_size = Vector2{ 2.0f,2.0f };
	m_size2 = Vector2::One;
	m_alpha = 255;
	m_t = 0.0f;
}

// タイトル演出の更新
void TitlePerformance::Update(float deltaTime)
{
	// パラメーター更新
	m_size = Vector2::Lerp(Vector2{ 2.0f,2.0f }, Vector2::One, m_t / 60.0f);
	m_size2 = Vector2::Lerp(Vector2::One, Vector2{ 5.0f,5.0f }, (m_t - 60.0f) / 600.0f);
	m_alpha = (int)MathHelper::Lerp(255, 0, (m_t - 60.0f) / 300.0f);

	m_t += deltaTime * 4.0f;
}

// タイトル演出の初描画
void TitlePerformance::Draw()const
{
	Graphics2D::draw_sprite((int)SpriteID::TitleBack, Vector2::Zero);
	Graphics2D::draw_sprite_RCS((int)SpriteID::TitleCharaBack,
		Vector2::Zero + Vector2{ 640.0f,360.0f }, 0, 0, 1280, 720, Vector2{ 640.0f,360.0f }, m_size);

	if (m_t >= 60.0f)
	{
		Graphics2D::draw_sprite_RCS_Alpha((int)SpriteID::TitleCharaBackFlash,
			Vector2::Zero + Vector2{ 640.0f,360.0f }, 0, 0, 1280, 720, Vector2{ 640.0f,360.0f }, m_size2, m_alpha);

		Graphics2D::draw_sprite((int)SpriteID::TitleLogo, Vector2::Zero);
		Graphics2D::draw_sprite((int)SpriteID::PAS, Vector2{ 260.0f,450.0f });
	}
}

bool TitlePerformance::Is_Complete() const
{
	if (m_t >= 60.0f)return true;

	return false;
}
