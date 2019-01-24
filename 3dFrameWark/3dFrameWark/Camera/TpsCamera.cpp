#include "TpsCamera.h"

#include "../World/IWorld.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../EventMessage.h"

#include "../Graphics3D/Graphics3D.h"
#include "../Graphics2D/Graphics2D.h"
#include "../Utility/Input/GamePad/GamePad.h"
#include "../Utility/MathHelper/MathHelper.h"
#include "../Utility//Quaternion/Quaternion.h"

#include <math.h>

TpsCamera::TpsCamera(IWorld& world, const Vector3& l_position, std::string l_targetName)
	:m_stateID{ CameraStateID::Normal },
	m_playerposition{ Vector3::Zero },
	m_playerrotate{ Matrix::Identity },
	m_backDis{ 45.0f },
	t{ 0.0f },
	m_yawAngle{ 0.0f },
	m_pitchAngle{ 0.0f },
	m_targetName{ l_targetName },
	m_group{ ActorGroup::Neutral }
{
	world_ = &world;
	m_name = "TpsCamera";
	m_position = l_position;
	m_lookPos = Vector3::Zero;
}

void TpsCamera::update(float deltaTime)
{
	if (m_targetName == "Chiya")
		m_group = ActorGroup::Player;
	else if (m_targetName == "Rize"|| m_targetName == "Syaro")
		m_group = ActorGroup::Enemy;

	auto l_player = world_->find_actor(m_group, m_targetName);
	if (l_player == nullptr)return;

	if (m_stateID == CameraStateID::Normal)
	{
		if (m_targetName == "Chiya")
			GetJoypadAnalogInputRight(&inputx_, &inputy_, DX_INPUT_KEY_PAD1);
		else if (m_targetName == "Rize" || m_targetName == "Syaro")
			GetJoypadAnalogInputRight(&inputx_, &inputy_, DX_INPUT_PAD2);

		m_yawAngle += deltaTime * (inputx_ / 500);
		m_pitchAngle =
			MathHelper::Clamp(m_pitchAngle -= deltaTime * (inputy_ / 1000), -40.0f, 40.0f);

		m_rotation = Matrix::CreateRotationX(m_pitchAngle) * Matrix::CreateRotationY(m_yawAngle);
		m_rotation.NormalizeRotationMatrix();

		const Vector3& l_backPosition = -(m_rotation.Forward().Normalize()* 35.0f);
		const Vector3& l_upPosition = Vector3{ 0.0f, 25.0f, 0.0f };
		m_to_target = l_player->get_position() - m_position;
		m_position = l_player->get_position() + l_backPosition + l_upPosition;
		//move(l_player->get_position() + l_backPosition + l_upPosition, 0.5f, 0.1f, 2.0f);
		m_lookPos = Vector3{
			l_player->get_position().x,
			l_player->get_position().y + 15.0f,
			l_player->get_position().z };

		if (GamePad::trigger(GamePad::X))
		{
			//m_stateID = CameraStateID::Cut;
		}
	}
	/*else if (m_stateID == CameraStateID::Cut)
	{
		m_position = Vector3::Lerp(
			l_player->get_position() + Vector3(3.0f, 10.0f, -20.0f),
			l_player->get_position() + Vector3(4.0f, 10.0f, -30.0f),
			t / 2.0f);
		t += 0.2f*deltaTime;
		if (GamePad::trigger(GamePad::B)
			|| t >= 8.0f)
		{
			t = 0.0f;
			m_stateID = CameraStateID::Normal;
		}
	}*/
	//world_->send_message(EventMessage::CameraMatrix, &get_pose());
}

void TpsCamera::move(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass)
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

void TpsCamera::draw() const
{
	if (m_targetName == "Chiya")
	{
		Graphics3D::viewport(0, 0, 640, 720);
		SetCameraScreenCenter(320.0f, 360.0f);

		
	}
	else if (m_targetName == "Rize" || m_targetName == "Syaro")
	{
		Graphics3D::viewport(640, 0, 1280, 720);
		SetCameraScreenCenter(960.0f, 360.0f);

		
	}

	

	Graphics3D::view_matrix(
		get_pose().CreateLookAt(m_position, m_lookPos, Vector3::Up)
	);

	Graphics3D::projection_matrix(
		Matrix::CreatePerspectiveFieldOfView(45.0f, 1280.0f / 720.0f, 0.3f, 2000.0f)
	);
}
