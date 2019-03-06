#ifndef _TITLE_PERFORMANCE_H_
#define _TITLE_PERFORMANCE_H_

#include "../../Utility/Vector2/Vector2.h"

//タイトル演出
class TitlePerformance
{
public:
	void Initialize();
	void Update(float deltaTime);
	void Draw()const;

	//演出が完了したか取得
	bool Is_Complete()const;

private:
	Vector2 m_size;
	Vector2 m_size2;

	int m_alpha;
	float m_t;
};

#endif