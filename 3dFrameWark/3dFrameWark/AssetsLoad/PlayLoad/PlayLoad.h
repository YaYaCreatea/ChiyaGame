#ifndef _PLAY_LOAD_H_
#define _PLAY_LOAD_H_

class PlayLoad
{
public:
	//�R���X�g���N�^
	PlayLoad();

	//�f�X�g���N�^
	~PlayLoad();

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