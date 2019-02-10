#ifndef _ANIMATED_MESH_H_
#define _ANIMATED_MESH_H_

#include "../SkeletalMesh/SkeletalMesh.h"
#include "../Animation/Animation.h"
#include <array>

class AnimatedMesh
{
public:
	using BoneMatrices = std::array<Matrix, 256>;

public:
	//�R���X�g���N�^
	AnimatedMesh(int l_mesh, int l_motion = 0);

	//�X�V
	void update(float deltaTime);

	//�`��
	void draw()const;

	//���[�V�����ύX
	void change_motion(int l_motion);

	void change_motion_same(int l_motion);

	//�X�P���g���̕ϊ��s����v�Z����
	void transform(const Matrix& l_world);

	//�X�P���g���̕ϊ��s����v�Z����
	void transform(const Matrix& l_world,int l_no, Vector3 m_pi);

	//�ϊ��s����擾
	const Matrix& get_bone_matrix(int l_no)const;

	//���[�V�����̏I�����Ԃ��擾
	float get_motion_end_time()const;

private:
	int m_mesh;						//���b�V��

	Animation animation_;			//�A�j���[�V����

	BoneMatrices m_world_matrices;	//�X�P���g���ϊ��s��
};

#endif