#ifndef _SKY_BOX_H_
#define _SKY_BOX_H_

#include "../ModelAsset/ModelAsset.h"
#include <string>

//�X�J�C�{�b�N�X�N���X
class SkyBox
{
public:
	//������
	static void initialize();
	//�I������
	static void finalize();
	//�ǂݍ���
	static bool load(int id, const std::string& file_name);
	//�폜
	static void erase(int id);
	//���b�V���̃o�C���h
	static void bind(int id);
	//�`��
	static void draw();

private:
	//�o�C���h���̃��f��
	static int model_;
	//���f���̃A�Z�b�g
	static ModelAsset asset_;
};

#endif