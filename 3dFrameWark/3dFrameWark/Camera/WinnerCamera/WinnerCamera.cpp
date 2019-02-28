#include "WinnerCamera.h"

#include "../../World/IWorld.h"

WinnerCamera::WinnerCamera(
	IWorld & world,
	const Vector3 & l_position, float l_yawAngle,
	std::string l_targetName)
	:m_playerposition{ Vector3::Zero },
	m_playerrotate{ Matrix::Identity },
	m_backDis{ 45.0f },
	t{ 0.0f },
	m_yawAngle{ l_yawAngle },
	m_pitchAngle{ 0.0f },
	m_targetName{ l_targetName },
	m_group{ ActorGroup::Neutral }
{
	world_ = &world;
	m_name = "DuelCamera";
	m_position = l_position;

	m_lookPos = Vector3::Zero;

	if (m_targetName == "Chiya")
	{
		m_group = ActorGroup::Chiya;
		chiyaWork_.WorkInitialize();
	}
	else if (m_targetName == "Rize")
		m_group = ActorGroup::Rize;
	else if (m_targetName == "Syaro")
	{
		m_group = ActorGroup::Syaro;
		syaroWork_.WorkInitialize();
	}
	else if (m_targetName == "Cocoa")
		m_group = ActorGroup::Cocoa;
}

void WinnerCamera::update(float deltaTime)
{
	auto l_player = world_->find_actor(m_group, m_targetName);
	if (l_player == nullptr)return;

	if (m_targetName == "Chiya")
		chiyaWork_.WorkUpdate(deltaTime, l_player->get_position(), m_position, m_lookPos, m_rotation);
	else if(m_targetName == "Syaro")
		syaroWork_.WorkUpdate(deltaTime, l_player->get_position(), m_position, m_lookPos, m_rotation);
	else
	{
		m_rotation = Matrix::CreateRotationX(m_pitchAngle) * Matrix::CreateRotationY(m_yawAngle);
		m_rotation.NormalizeRotationMatrix();

		Vector3& l_backPosition = (m_rotation.Forward().Normalize()* 18.0f);
		const Vector3& l_upPosition = Vector3{ 5.0f, 18.0f, 0.0f };

		m_position = l_player->get_position() + l_backPosition + l_upPosition;
		m_lookPos = Vector3{
			l_player->get_position().x - 3.0f,
			l_player->get_position().y + 14.0f,
			l_player->get_position().z };
	}
}

void WinnerCamera::draw() const
{
	Graphics3D::viewport(0, 0, 1280, 720);

	Graphics3D::view_matrix(
		get_pose().CreateLookAt(m_position, m_lookPos, Vector3::Up)
	);

	Graphics3D::projection_matrix(
		Matrix::CreatePerspectiveFieldOfView(38.0f, 1280.0f / 720.0f, 1.0f, 1000.0f)
	);
}
