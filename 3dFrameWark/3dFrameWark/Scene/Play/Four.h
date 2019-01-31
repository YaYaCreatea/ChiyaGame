#ifndef _FOUR_H_
#define _FOUR_H_

#include "../../Scene/IScene.h"

#include "../../World/World.h"
#include "../../Camera/FrameCamera/FrameCamera.h"

#include "../../AssetsLoad/PlayLoad/PlayLoad.h"

class Four :public IScene
{
public:
	Four(PlayLoad& l_load);
	void start()override;
	void update(float deltaTime)override;
	void draw()const override;
	bool is_end()const override;
	SceneID next() const override;
	void end()override;

private:
	void EndCheck();

private:
	PlayLoad* load_{ nullptr };

	World world_;
	FrameCamera frameCamera_;

	bool m_isEnd;	//èIóπÉtÉâÉO
};

#endif