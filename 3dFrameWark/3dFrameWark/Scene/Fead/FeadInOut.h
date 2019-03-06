#ifndef _FEAD_IN_OUT_H_
#define _FEAD_IN_OUT_H_

//フェードインアウト
class FeadInOut
{
public:
	void Initialize(int l_startAlpha = 255);

	//フェードイン
	void FeadIn(float deltaTime);

	//フェードアウト
	void FeadOut(float deltaTime);

	void DrawBack()const;

	//フェードしているか取得
	bool IsFead()const;

private:
	int m_alpha;
	bool m_isFead;
};

#endif
