#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "../EffectAsset/EffectAsset.h"
#include "../Utility/Vector3/Vector3.h"
#include <string>

//�r���{�[�h
class Effect
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

	static void update();

	static void play(int id,const Vector3& position, float pitch = 0.0f, float yaw = 0.0f, float roll = 0.0f);

	//�o�C���h
	static void bind(int id);

	//�`��
	static void draw();

private:
	//�o�C���h���̃G�t�F�N�g
	static int efk_;
	//�G�t�F�N�g�A�Z�b�g
	static EffectAsset effect_;
};

#endif