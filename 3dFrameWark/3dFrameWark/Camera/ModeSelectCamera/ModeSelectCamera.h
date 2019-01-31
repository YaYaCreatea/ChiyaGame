#ifndef _MODE_SELECT_CAMERA_H_
#define _MODE_SELECT_CAMERA_H_

#include "../../Utility/Matrix/Matrix.h"
#include "../../Utility/Vector3/Vector3.h"

//モードセレクト用カメラ
class ModeSelectCamera
{
public:
	ModeSelectCamera();
	~ModeSelectCamera();
	void initialize();
	void update(float deltaTime);
	void drawBack()const;
	void finalize();

	Matrix get_pose()const;

private:
	Matrix m_stageRotation{ Matrix::Identity };
	Vector3 m_position{ Vector3::Zero};
};

#endif