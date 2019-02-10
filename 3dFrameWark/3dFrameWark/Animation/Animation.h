#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "../SkeletalMesh/SkeletalMesh.h"
#include <array>

class Animation
{
public:
	using Matrices = std::array<Matrix, 256>;

public:
	//�R���X�g���N�^
	Animation(int l_model, int l_motion);

	//�X�V
	void update(float deltaTime);

	//���[�V�����ύX
	void change_motion(int l_motion);

	void change_motion_same(int l_motion);

	//���ݍĐ����̃��[�V����
	int get_current_motion();

	//�ϊ��s����擾
	const Matrices& get_local_matrices()const;

	//�{�[�������擾
	int get_bone_count()const;

	//�I�����Ԃ��擾
	float get_end_time()const;

private:
	const float LERPTIME{ 10.0f };	//��ԃt���[����

	int m_model{ 0 };				//�A�j���[�V�����ԍ�
	int m_motion{ 0 };				//�Đ����̃��[�V�����ԍ�
	float m_motionTimer{ 0.0f };	//�Đ����̃A�j���[�V�����^�C�}

	int m_prev_motion{ 0 };				//�O��Đ��������[�V�����ԍ�
	float m_prev_motionTimer{ 0.0f };	//�O��Đ������ŏI�A�j���[�V�����^�C�}

	float m_lerpTimer{ 0.0f };		//��ԃA�j���[�V�����^�C�}

	Matrices m_local_matrices;		//�A�j���[�V�����ϊ��s��
};

#endif