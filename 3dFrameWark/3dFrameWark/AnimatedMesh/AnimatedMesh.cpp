#include "AnimatedMesh.h"
#include "../Utility/Vector3/Vector3.h"

AnimatedMesh::AnimatedMesh(int l_mesh, int l_motion)
	:m_mesh{ l_mesh }, animation_{ l_mesh,l_motion }
{
}

void AnimatedMesh::update(float deltaTime)
{
	animation_.update(deltaTime);
}

void AnimatedMesh::draw() const
{
	SkeletalMesh::bind(m_mesh);
	SkeletalMesh::set_world_matrices(m_world_matrices.data());
	SkeletalMesh::draw();
}

void AnimatedMesh::change_motion(int l_motion)
{
	animation_.change_motion(l_motion);
}

void AnimatedMesh::transform(const Matrix & l_world)
{
	SkeletalMesh::bind(m_mesh);
	SkeletalMesh::set_local_matrices(animation_.get_local_matrices().data());
	SkeletalMesh::transform(l_world);
	SkeletalMesh::get_world_matrices(m_world_matrices.data());
}

void AnimatedMesh::transform(const Matrix & l_world, int l_no, Vector3 m_pi)
{
	SkeletalMesh::bind(m_mesh);
	SkeletalMesh::set_local_matrices(animation_.get_local_matrices().data());
	SkeletalMesh::transform(l_world*Matrix(Matrix::Identity).Translation(m_pi));
	SkeletalMesh::get_world_matrices(m_world_matrices.data(), l_no);
}

const Matrix & AnimatedMesh::get_bone_matrix(int l_no) const
{
	return m_world_matrices[l_no];
}

float AnimatedMesh::get_motion_end_time() const
{
	return animation_.get_end_time();
}
