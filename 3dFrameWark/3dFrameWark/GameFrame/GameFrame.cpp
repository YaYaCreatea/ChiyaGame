#include "GameFrame.h"

#include "../Scene/SceneID.h"
#include "../Scene/Title/Title.h"
#include "../Scene/Play/GamePlay.h"

GameFrame::GameFrame()
	:Game{ 1280,720,false }
{
}

void GameFrame::start()
{
	sceneManager_.Add_Scece(SceneID::Title, new_scene<Title>());
	sceneManager_.Add_Scece(SceneID::Game, new_scene<GamePlay>());
	sceneManager_.Change_Scene(SceneID::Game);
}

void GameFrame::update(float deltaTime)
{
	sceneManager_.update(deltaTime);
}

void GameFrame::draw()
{
	sceneManager_.draw();
}

void GameFrame::end()
{
	sceneManager_.end();
}
