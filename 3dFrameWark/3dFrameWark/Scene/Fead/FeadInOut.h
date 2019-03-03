#ifndef _FEAD_IN_OUT_H_
#define _FEAD_IN_OUT_H_

class FeadInOut
{
public:
	void Initialize(int l_startAlpha = 255);
	void FeadIn(float deltaTime);
	void FeadOut(float deltaTime);
	void DrawBack()const;
	bool IsFead()const;

private:
	int m_alpha;
	bool m_isFead;
};

#endif
