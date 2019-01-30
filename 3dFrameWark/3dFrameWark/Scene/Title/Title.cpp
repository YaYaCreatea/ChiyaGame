#include "Title.h"
#include "../SceneID.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../assetsID/AssetsID.h"

void Title::start()
{
	m_isEnd = false;
	input_.initialize(DX_INPUT_PAD1);

	Graphics2D::initialize();
	Graphics2D::load_sprite((int)SpriteID::TitleBack, "asset/2Dsprite/Title/TitleBack.png");
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
	Graphics2D::finalize();
}
