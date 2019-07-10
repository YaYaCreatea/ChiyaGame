#include "AttackBullet.h"

#include "../../../CollisionMesh/CollisionMesh.h"
#include "../../../Billboard/Billboard.h"

#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"


AttackBullet::AttackBullet(std::string l_name, const Vector3 & l_position, float l_radius, const Matrix & matrix, int l_billbordID)
	:m_billBoardID{ l_billbordID },
	m_radius{ l_radius },
	m_timer{ 120.0f },
	m_bulletSpeed{ 2.5f },
	m_angle{ 0.0f }
{
	m_name = l_name;
	m_position = l_position;

	// 当たり判定の生成
	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,m_radius,0.0f },Vector3{ 0.0f,m_radius,0.0f },m_radius };

	// 回転設定
	m_rotation.Forward(matrix.Forward());
	m_rotation.Right(matrix.Right());

	// SE再生
	Sound::play_se((int)SoundID_SE::GunShot);
}

void AttackBullet::update(float deltaTime)
{
	// 移動制御
	m_position += (m_rotation.Forward()*m_bulletSpeed)*deltaTime;

	// 消滅チェック
	if (m_timer <= 0.0f || StageReact())
		m_isdead = true;
	m_timer -= 1.0f*deltaTime;

	// 回転値更新
	m_angle += 0.1f*deltaTime;
}

void AttackBullet::draw() const
{
	Billboard::bind(m_billBoardID);
	Billboard::draw(m_position + Vector3{ 0.0f,m_radius,0.0f }, m_radius*2.0f, 0.5f, 0.5f, m_angle);

	//当たり判定
	//bodyCapsule_.draw(get_pose());
}

void AttackBullet::react(Actor & other)
{
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
