#ifndef _FEAD_IN_OUT_H_
#define _FEAD_IN_OUT_H_

//�t�F�[�h�C���A�E�g
class FeadInOut
{
public:
	void Initialize(int l_startAlpha = 255);

	//�t�F�[�h�C��
	void FeadIn(float deltaTime);

	//�t�F�[�h�A�E�g
	void FeadOut(float deltaTime);

	void DrawBack()const;

	//�t�F�[�h���Ă��邩�擾
	bool IsFead()const;

private:
	int m_alpha;
	bool m_isFead;
};

#endif
