#include "GameFrame.h"

#include "../Scene/SceneID.h"

#include "../Scene/Title/Title.h"
#include "../Scene/ModeSelect/ModeSelect.h"
#include "../Scene/Play/GamePlay.h"
#include "../Scene/Play/Duel.h"
#include "../Scene/Play/Four.h"

GameFrame::GameFrame()
	:Game{ 1280,720,false }
{
}

void GameFrame::start()
{
	sceneManager_.Add_Scece(SceneID::Title, new_scene<Title>());
	sceneManager_.Add_Scece(SceneID::Select, new_scene<ModeSelect>());
	sceneManager_.Add_Scece(SceneID::GameDuel, new_scene<Duel>());
	sceneManager_.Add_Scece(SceneID::GameFour, new_scene<Four>());
	sceneManager_.Change_Scene(SceneID::Select);
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
