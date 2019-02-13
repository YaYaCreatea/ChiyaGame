#include "GameFrame.h"

#include "../Scene/SceneID.h"

#include "../Scene/Load/StartUp.h"
#include "../Scene/Title/Title.h"
#include "../Scene/ModeSelect/ModeSelect.h"
#include "../Scene/CharaSelect/CharaSelect.h"
#include "../Scene/Load/ToPlay.h"
#include "../Scene/Play/GamePlay.h"
#include "../Scene/Play/Duel.h"
#include "../Scene/Play/Four.h"

GameFrame::GameFrame()
	:Game{ 1280,720,false }
{
}

void GameFrame::start()
{
	sceneParameters_.initialize();
	selecter_.initialize();

	sceneManager_.Add_Scece(SceneID::StartUp, new_scene<StartUp>(startUpload_));
	sceneManager_.Add_Scece(SceneID::Title, new_scene<Title>());
	sceneManager_.Add_Scece(SceneID::Select, new_scene<ModeSelect>(sceneParameters_, startUpload_));
	sceneManager_.Add_Scece(SceneID::CharaSelect, new_scene<CharaSelect>(selecter_,sceneParameters_, startUpload_));
	sceneManager_.Add_Scece(SceneID::GameLoad, new_scene<ToPlay>(sceneParameters_, playload_));
	sceneManager_.Add_Scece(SceneID::GameDuel, new_scene<Duel>(playload_));
	sceneManager_.Add_Scece(SceneID::GameFour, new_scene<Four>(playload_));
	sceneManager_.Change_Scene(SceneID::StartUp);
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
