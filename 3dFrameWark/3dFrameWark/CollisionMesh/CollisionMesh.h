#ifndef _COLLISION_MESH_H_
#define _COLLISION_MESH_H_

#include "../Utility/Vector3/Vector3.h"
#include <string>
#include "../ModelAsset/ModelAsset.h"

//�Փ˔���p���b�V���N���X
class CollisionMesh
{
public:
	//������
	static void initialize();
	//�I������
	static void finalize();
	//�ǂݍ���
	static bool load(int id, const std::string& file_name, int frame = -1, int div_x = 32, int div_y = 8, int div_z = 32);
	//�폜
	static void erase(int id);
	//���b�V���̃o�C���h
	static void bind(int id);
	//�`��
	static void draw();
	//�����Ƃ̏Փ˔���
	static bool collide_line(const Vector3&start, const Vector3& end, Vector3*point = nullptr, Vector3*normal = nullptr);
	//���̂Ƃ̏Փ˔���
	static bool collide_sphere(const Vector3& center, const Vector3&center2, float radius, Vector3* result = nullptr);

private:
	//�Փ˔���p�̃��f���n���h��
	static int model_;
	//���f���A�Z�b�g
	static ModelAsset asset_;
};

#endif