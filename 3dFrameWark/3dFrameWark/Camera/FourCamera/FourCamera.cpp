#include "FourCamera.h"

#include "../../World/IWorld.h"

#include "../../ActorGroupManager/ActorGroup.h"
#include "../../EventMessage.h"

#include "../../Graphics3D/Graphics3D.h"
#include "../../Graphics2D/Graphics2D.h"
#include "../../Utility/Input/GamePad/GamePad.h"
#include "../../Utility/MathHelper/MathHelper.h"
#include "../../Utility//Quaternion/Quaternion.h"
#include "../../CollisionMesh/CollisionMesh.h"

#include "../../assetsID/AssetsID.h"

#include <math.h>

FourCamera::FourCamera(IWorld & world, const Vector3 & l_position, float l_yawAngle, std::string l_targetName)
	:m_stateID{ CameraStateID::Normal },
	m_playerposition{ Vector3::Zero },
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
		m_group = ActorGroup::Chiya;
	else if (m_targetName == "Rize")
		m_group = ActorGroup::Rize;
	else if (m_targetName == "Syaro")
		m_group = ActorGroup::Syaro;
	else if (m_targetName == "Cocoa")
		m_group = ActorGroup::Cocoa;

	m_inputX = 0;
	m_inputY = 0;
}

void FourCamera::update(float deltaTime)
{
	auto l_player = world_->find_actor(m_group, m_targetName);
	if (l_player == nullptr)return;

	if (m_stateID == CameraStateID::Normal)
	{
		if (m_targetName == "Chiya")
			GetJoypadAnalogInputRight(&m_inputX, &m_inputY, DX_INPUT_PAD1);
		else if (m_targetName == "Rize")
			GetJoypadAnalogInputRight(&m_inputX, &m_inputY, DX_INPUT_PAD2);
		else if (m_targetName == "Syaro")
			GetJoypadAnalogInputRight(&m_inputX, &m_inputY, DX_INPUT_PAD3);
		else if (m_targetName == "Cocoa")
			GetJoypadAnalogInputRight(&m_inputX, &m_inputY, DX_INPUT_PAD4);

		m_yawAngle += deltaTime * (m_inputX / 500);
		m_pitchAngle =
			MathHelper::Clamp(m_pitchAngle -= deltaTime * (m_inputY / 1000), -40.0f, 40.0f);

		m_rotation = Matrix::CreateRotationX(m_pitchAngle) * Matrix::CreateRotationY(m_yawAngle);
		m_rotation.NormalizeRotationMatrix();

		const Vector3& l_backPosition = -(m_rotation.Forward().Normalize()* 80.0f);
		const Vector3& l_upPosition = Vector3{ 0.0f, 25.0f, 0.0f };
		m_to_target = l_player->get_position() - m_position;
		m_position = l_player->get_position() + l_backPosition + l_upPosition;
		m_lookPos = Vector3{
			l_player->get_position().x,
			l_player->get_position().y + 16.0f,
			l_player->get_position().z };

		CollisionMesh::collide_line(m_position, m_lookPos, &m_position);
	}
}

void FourCamera::draw() const
{
	if (m_targetName == "Chiya")
	{
		Graphics3D::viewport(0, 0, 640, 360);
		SetCameraScreenCenter(320.0f, 180.0f);
	}
	else if (m_targetName == "Rize")
	{
		Graphics3D::viewport(640, 0, 1280, 360);
		SetCameraScreenCenter(960.0f, 180.0f);
	}
	else if (m_targetName == "Syaro")
	{
		Graphics3D::viewport(0, 360, 640, 720);
		SetCameraScreenCenter(320.0f, 540.0f);
	}
	else if (m_targetName == "Cocoa")
	{
		Graphics3D::viewport(640, 360, 1280, 720);
		SetCameraScreenCenter(960.0f, 540.0f);
	}

	Graphics3D::view_matrix(
		get_pose().CreateLookAt(m_position, m_lookPos, Vector3::Up)
	);

	Graphics3D::projection_matrix(
		Matrix::CreatePerspectiveFieldOfView(45.0f, 1280.0f / 720.0f, 1.0f, 1000.0f)
	);
}

void FourCamera::move(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass)
{
	//バネの伸び具合を計算
	const auto stretch = m_position - l_rest_position;
	//バネの力を計算
	const auto force = -l_stiffness * stretch;
	//加速度を追加
	const auto acceleration = force / l_mass;
	//移動速度を計算
	m_velocity = l_friction * (m_velocity + acceleration);
	//座標の更新
	m_position += m_velocity;
}
