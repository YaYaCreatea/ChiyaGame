#include "Animation.h"

Animation::Animation(int l_model, int l_motion)
	:m_model{ l_model },
	m_motion{ l_motion },
	m_prev_motion{ l_motion }
{
	SkeletalMesh::bind(m_model);
	SkeletalMesh::bind_animation(m_motion, m_motionTimer);
	SkeletalMesh::get_local_matrices(m_local_matrices.data());
}

void Animation::update(float deltaTime)
{
	SkeletalMesh::bind(m_model);
	SkeletalMesh::bind_animation(m_prev_motion, m_prev_motionTimer, m_motion, m_motionTimer, m_lerpTimer / LERPTIME);
	SkeletalMesh::get_local_matrices(m_local_matrices.data());

	m_motionTimer = std::fmod(m_motionTimer + 0.5f*deltaTime, get_end_time());
	m_lerpTimer = std::fmin(m_lerpTimer + deltaTime, LERPTIME);
}

void Animation::change_motion(int l_motion)
{
	//åªç›Ç∆ìØÉÇÅ[ÉVÉáÉìÇÃèÍçáreturn
	if (m_motion == l_motion)return;

	m_prev_motion = m_motion;
	m_prev_motionTimer = m_motionTimer;

	m_motion = l_motion;
	m_motionTimer = 0.0f;

	m_lerpTimer = 0.0f;
}

int Animation::get_current_motion()
{
	return m_motion;
}

const Animation::Matrices & Animation::get_local_matrices() const
{
	return m_local_matrices;
}

int Animation::get_bone_count() const
{
	SkeletalMesh::bind(m_model);
	return SkeletalMesh::bone_count();
}

float Animation::get_end_time() const
{
	SkeletalMesh::bind(m_model);
	return SkeletalMesh::end_time(m_motion);
}
