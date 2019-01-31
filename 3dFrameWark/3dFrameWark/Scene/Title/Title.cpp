#include "Title.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../Graphics2D/Graphics2D.h"

void Title::start()
{
	m_isEnd = false;
	input_.initialize(DX_INPUT_PAD1);
}

void Title::update(float deltaTime)
{
	input_.update();
	if (input_.Trigger(PAD_INPUT_1))
		m_isEnd = true;
}

void Title::draw() const
{
	Graphics2D::draw_sprite((int)SpriteID::TitleBack, Vector2::Zero);
}

bool Title::is_end() const
{
	return m_isEnd;
}

SceneID Title::next() const
{
	return SceneID::Select;
}

void Title::end()
{
}
