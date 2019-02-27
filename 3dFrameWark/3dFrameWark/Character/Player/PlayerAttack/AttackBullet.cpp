#include "AttackBullet.h"

#include "../../../CollisionMesh/CollisionMesh.h"
#include "../../../Billboard/Billboard.h"

#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"


AttackBullet::AttackBullet(std::string l_name, const Vector3 & l_position, float l_radius, const Matrix & matrix)
	:m_radius{ l_radius },
	m_timer{ 120.0f },
	m_bulletSpeed{ 2.5f },
	m_angle{ 0.0f }
{
	m_name = l_name;
	m_position = l_position;

	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,m_radius,0.0f },Vector3{ 0.0f,m_radius,0.0f },m_radius };

	//effectID = LoadEffekseerEffect("asset/Effect/Beam/Drill.efk");
	//effectIDs = PlayEffekseer3DEffect(effectID);

	m_rotation.Forward(matrix.Forward());
	m_rotation.Right(matrix.Right());

	Sound::play_se((int)SoundID_SE::GunShot);
}

void AttackBullet::update(float deltaTime)
{
	m_position += (m_rotation.Forward()*m_bulletSpeed)*deltaTime;

	//SetPosPlayingEffekseer3DEffect(effectIDs, m_position.x, m_position.y, m_position.z);
	//UpdateEffekseer3D();

	if (m_timer <= 0.0f || StageReact())
		m_isdead = true;
	m_timer -= 1.0f*deltaTime;

	m_angle += 0.1f*deltaTime;
}

void AttackBullet::draw() const
{
	Billboard::bind(0);
	Billboard::draw(m_position + Vector3{ 0.0f,m_radius,0.0f }, m_radius*2.0f, 0.5f, 0.5f, m_angle);

	//DrawEffekseer3D();

	//“–‚½‚è”»’è
	//bodyCapsule_.draw(get_pose());
}

void AttackBullet::react(Actor & other)
{
	//StopEffekseer3DEffect(effectIDs);
	m_isdead = true;
}

bool AttackBullet::StageReact()
{
	return CollisionMesh::collide_capsule(
		m_position + Vector3{ 0.0f,m_radius,0.0f },
		m_position + Vector3{ 0.0f,m_radius,0.0f },
		m_radius,
		&m_position);
}
