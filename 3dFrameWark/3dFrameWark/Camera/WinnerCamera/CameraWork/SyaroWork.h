#ifndef _SYARO_WORK_H_
#define _SYARO_WORK_H_

#include "../../../Utility/Vector3/Vector3.h"
#include "../../../Utility/Matrix/Matrix.h"

enum class WorkStateSyaro
{
	Work0,
	Work1,
};

class SyaroWork
{
public:
	SyaroWork();
	void WorkInitialize();
	void WorkUpdate(float deltaTime,
		const Vector3& l_syaroPosition,
		Vector3& l_position, Vector3& l_lookPosition, Matrix& l_rotation);

private:
	WorkStateSyaro m_state;
	float m_back;
	float m_value;
	float m_timer;
};

#endif