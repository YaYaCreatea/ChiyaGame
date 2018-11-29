#ifndef _BILL_BOARD_H_
#define _BILL_BOARD_H_

#include "../TextureAsset/TextureAsset.h"
#include "../Utility/Vector3/Vector3.h"
#include <string>

//�r���{�[�h
class Billboard
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

	//�o�C���h
	static void bind(int id);

	//�`��
	static void draw(const Vector3& position, float size, float cx = 0.5f, float cy = 0.5f, float angle = 0.0f);

private:
	//�o�C���h���̃C���[�W
	static int image_;
	//�e�N�X�`���A�Z�b�g
	static TextureAsset asset_;
};

#endif