#include "NullScene.h"
#include "../SceneID.h"

void NullScene::start()
{
}

void NullScene::update(float deltaTime)
{
}

void NullScene::draw() const
{
}

bool NullScene::is_end() const
{
	return false;
}

SceneID NullScene::next() const
{
	return SceneID::Null;
}

void NullScene::end()
{
}
