#ifndef _CHIYA_WORK_H_
#define _CHIYA_WORK_H_

#include "../../../Utility/Vector3/Vector3.h"
#include "../../../Utility/Matrix/Matrix.h"

enum class WorkStateChiya
{
	Work0,
	Work1,
};

class ChiyaWork
{
public:
	ChiyaWork();
	void WorkInitialize();
	void WorkUpdate(float deltaTime, 
		const Vector3& l_chiyaPosition, 
		Vector3& l_position, Vector3& l_lookPosition, Matrix& l_rotation);

private:
	WorkStateChiya m_state;
	float m_back;
	float m_value;
	float m_timer;
};

#endif