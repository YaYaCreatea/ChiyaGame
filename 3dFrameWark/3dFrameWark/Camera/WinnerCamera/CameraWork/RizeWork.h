#ifndef _RIZE_WORK_H_
#define _RIZE_WORK_H_

#include "../../../Utility/Vector3/Vector3.h"
#include "../../../Utility/Matrix/Matrix.h"

enum class WorkStateRize
{
	Work0,
	Work1,
};

class RizeWork
{
public:
	RizeWork();
	void WorkInitialize();
	void WorkUpdate(float deltaTime,
		const Vector3& l_chiyaPosition,
		Vector3& l_position, Vector3& l_lookPosition, Matrix& l_rotation);

private:
	WorkStateRize m_state;
	float m_back;
	float m_value;
	float m_timer;
};

#endif