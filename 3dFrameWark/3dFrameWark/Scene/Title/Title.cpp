#include "Title.h"
#include "../SceneID.h"

void Title::start()
{
	m_isEnd = false;
	input_.initialize(DX_INPUT_KEY_PAD1);
}

void Title::update(float deltaTime)
{
	input_.update();
	if (input_.Trigger(PAD_INPUT_1))
		m_isEnd = true;
}

void Title::draw() const
{
}

bool Title::is_end() const
{
	return m_isEnd;
}

SceneID Title::next() const
{
	return SceneID::Game;
}

void Title::end()
{
}
