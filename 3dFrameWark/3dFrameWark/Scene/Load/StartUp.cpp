#include "StartUp.h"

#include "../SceneID.h"
#include "../../assetsID/AssetsID.h"

#include "../../Utility/Vector2/Vector2.h"
#include "../../Graphics2D/Graphics2D.h"

StartUp::StartUp(StartUpLoad & l_load)
{
	load_ = &l_load;
}

void StartUp::start()
{
	m_isEnd = false;
	m_nextTimer = 0.0f;

	//�^�C�g���`���[�h�Z���N�g�܂ł̃��\�[�X���[�h
	load_->Load();
}

void StartUp::update(float deltaTime)
{
	//�ǂݍ��݊�����90�b��Ɉڍs
	if (GetASyncLoadNum() == 0)
	{
		if (m_nextTimer >= 90.0f)
			m_isEnd = true;
		m_nextTimer += deltaTime;
	}
}

void StartUp::draw() const
{
	Graphics2D::draw_sprite((int)SpriteID::NLLogo, Vector2{ 500.0f,390.0f });

	//�Q�[�W	
	Graphics2D::draw_sprite_rect(
		(int)SpriteID::LoadGauge, Vector2{ 420.0f,320.0f },
		0, 0, 450 - ((450 / load_->get_loadNum())*GetASyncLoadNum()), 40
	);
	Graphics2D::draw_sprite((int)SpriteID::LoadFrame, Vector2{ 420.0f,320.0f });
}

bool StartUp::is_end() const
{
	return m_isEnd;
}

SceneID StartUp::next() const
{
	//���[�h�Z���N�g��
	return SceneID::Title;
}

void StartUp::end()
{
}
