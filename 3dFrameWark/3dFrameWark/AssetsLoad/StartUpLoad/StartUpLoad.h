#ifndef _START_UP_LOAD_H_
#define _START_UP_LOAD_H_

class StartUpLoad
{
public:
	//�R���X�g���N�^
	StartUpLoad();

	//�f�X�g���N�^
	~StartUpLoad();

	//�A�Z�b�g�ǂݍ���
	void Load();

	//�A�Z�b�g�A�����[�h
	void UnLoad();

	//�ǂݍ��݃A�Z�b�g���擾
	int get_loadNum()const;

private:
	int m_loadNum;
};

#endif