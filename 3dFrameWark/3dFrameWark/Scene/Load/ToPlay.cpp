#include "ToPlay.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../Graphics2D/Graphics2D.h"

ToPlay::ToPlay(SceneParameters& l_sceneParameters, PlayLoad& l_load)
{
	sceneParameters_ = &l_sceneParameters;
	load_ = &l_load;
}

void ToPlay::start()
{
	m_isEnd = false;
	m_nextTimer = 0.0f;

	//�v���C���[�h�̃��\�[�X���[�h
	load_->Load();
}

void ToPlay::update(float deltaTime)
{
	//�ǂݍ��݊�����90�b��Ɉڍs
	if (GetASyncLoadNum() == 0)
	{
		if (m_nextTimer >= 90.0f)
			m_isEnd = true;
		m_nextTimer += deltaTime;
	}
}

void ToPlay::draw() const
{
	//�Q�[�W
	Graphics2D::draw_sprite_rect(
		(int)SpriteID::LoadGauge, Vector2{ 500.0f,300.0f },
		0, 0, 340 - ((340 / 18)*GetASyncLoadNum()), 30
	);

	//�f�o�b�O�\��(�ǂݍ��ݐi��)
	DrawFormatStringF(
		640.0f, 360.0f, GetColor(255, 255, 255),
		"(%d/%d)", load_->get_loadNum() - GetASyncLoadNum(), load_->get_loadNum()
	);
}

bool ToPlay::is_end() const
{
	return m_isEnd;
}

SceneID ToPlay::next() const
{
	//Duel or Four
	return sceneParameters_->Get_NextSceneID();
	//return SceneID::Result;
}

void ToPlay::end()
{
}
