#ifndef _FRAME_CAMERA_H_
#define _FRAME_CAMERA_H_

#include "../../Scene/CharaSelect/CharacterSelecter.h"

//フレームUI用カメラ
class FrameCamera
{
public:
	FrameCamera();
	~FrameCamera();

	void initialize(CharacterSelecter& l_selecter);
	void drawDuel()const;
	void drawFour()const;	

private:
	CharacterSelecter* charaSelecter_{ nullptr };
};

#endif
