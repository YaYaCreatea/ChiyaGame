#ifndef _COCOA_WORK_H_
#define _COCOA_WORK_H_

#include "../../../Utility/Vector3/Vector3.h"
#include "../../../Utility/Matrix/Matrix.h"

enum class WorkStateCocoa
{
	Work0,
	Work1,
	Work2,
};

class CocoaWork
{
public:
	CocoaWork();
	void WorkInitialize();
	void WorkUpdate(float deltaTime,
		const Vector3& l_chiyaPosition,
		Vector3& l_position, Vector3& l_lookPosition, Matrix& l_rotation);

private:
	WorkStateCocoa m_state;
	float m_value0;
	float m_value1;
	float m_value2;
	float m_value3;
	float m_timer;
};

#endif