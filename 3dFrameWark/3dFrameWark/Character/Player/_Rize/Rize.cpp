#include "Rize.h"

#include "../../../World/IWorld.h"
#include "../../../ActorGroupManager/ActorGroup.h"

#include "../../../Utility/Input/GamePad/GamePad.h"
#include "../../../StaticMesh/StaticMesh.h"
#include "../../../SkeletalMesh/SkeletalMesh.h"
#include "../../../Utility/MathHelper/MathHelper.h"
#include "../../../Utility/Quaternion/Quaternion.h"
#include "../../../EventMessage.h"

#include "../../../CollisionMesh/CollisionMesh.h"


#include "../../../Graphics2D/Graphics2D.h"
#include "../../../Graphics3D/Graphics3D.h"
#include "../../../Sound/Sound.h"
#include "../../../assetsID/AssetsID.h"

#include "../../../Camera/DuelCamera/DuelCamera.h"
#include "../../../Camera/FourCamera/FourCamera.h"
#include "../PlayerAction/PlayerAction_Idle.h"
#include "../PlayerAction/PlayerAction_Move.h"
#include "../PlayerAction/PlayerAction_Attack.h"
#include "../PlayerAction/PlayerAction_Break.h"
#include "../PlayerAction/PlayerAction_Jump.h"
#include "../PlayerAction/PlayerAction_Damage.h"
#include "../PlayerAction/PlayerAction_DamageBreak.h"
#include "../PlayerAction/PlayerAction_Down.h"
#include "../PlayerAction/PlayerAction_DownIdle.h"
#include "../PlayerAction/PlayerAction_Dash.h"
#include "../PlayerAction/PlayerAction_AttackHoming.h"

#include "../CharacterAnimationID.h"
#include "../../../assetsID/AssetsID.h"

#include <EffekseerForDXLib.h>


Rize::Rize(IWorld & world,
	std::string l_name, const Vector3 & l_position, Matrix l_rotate,
	int l_model, int l_weapon,
	int l_numPlayer, int l_gMode
)
	:mesh_{ l_model,0 }, 
	shape_{ l_model },
	input_{},
	m_state{ PlayerStateName::Idle },
	m_motion{ 0 },
	m_weapon{ l_weapon },
	m_pi{ l_position + Vector3::Zero },
	m_piVelo{ Vector3::Zero },
	m_forward{ Vector3::Zero }
{
	world_ = &world;
	m_name = l_name;
	m_rotation = l_rotate;
	m_position = l_position;
	m_prevposition = m_position;
	m_numPlayer = l_numPlayer;
	m_gameMode = l_gMode;

	// 体力,パラメーター設定
	parameters_.Initialize(m_name, 60);

	// 1on1の場合
	if (m_gameMode == 0)
	{
		if (m_numPlayer == 1)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<DuelCamera>(world, m_position, 180.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD1);
		}
		else if (m_numPlayer == 2)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<DuelCamera>(world, m_position, 0.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD2);
		}
	}
	// 4人対戦の場合
	else
	{
		if (m_numPlayer == 1)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<FourCamera>(world, m_position, 135.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD1);
		}
		else if (m_numPlayer == 2)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<FourCamera>(world, m_position, 0.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD2);
		}
		else if (m_numPlayer == 3)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<FourCamera>(world, m_position, 180.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD3);
		}
		else if (m_numPlayer == 4)
		{
			//カメラ生成
			world_->add_camera_rize(new_actor<FourCamera>(world, m_position, -45.0f, m_name, m_numPlayer));
			input_.initialize(DX_INPUT_PAD4);
		}
	}

	// 状態の追加,設定
	playerActions_[PlayerStateName::Idle].add(new_action<PlayerAction_Idle>(world, parameters_, input_));
	playerActions_[PlayerStateName::Move].add(new_action<PlayerAction_Move>(world, parameters_, input_));
	playerActions_[PlayerStateName::Attack].add(new_action<PlayerAction_Attack>(world, parameters_, input_));
	playerActions_[PlayerStateName::Break].add(new_action<PlayerAction_Break>(world, parameters_, input_));
	playerActions_[PlayerStateName::Jump].add(new_action<PlayerAction_Jump>(world, parameters_, input_));
	playerActions_[PlayerStateName::Damage].add(new_action<PlayerAction_Damage>(world, parameters_));
	playerActions_[PlayerStateName::DamageBreak].add(new_action<PlayerAction_DamageBreak>(world, parameters_));
	playerActions_[PlayerStateName::Down].add(new_action<PlayerAction_Down>(world, parameters_));
	playerActions_[PlayerStateName::DownIdle].add(new_action<PlayerAction_DownIdle>(world, parameters_));
	playerActions_[PlayerStateName::Dash].add(new_action<PlayerAction_Dash>(world, parameters_, input_));
	playerActions_[PlayerStateName::AttackHoming].add(new_action<PlayerAction_AttackHoming>(world, parameters_, input_));
	playerActions_[m_state].initialize();

	// 当たり判定生成
	bodyCapsule_ = BoundingCapsule{ Vector3{ 0.0f,3.0f,0.0f },Vector3{0.0f,20.0f,0.0f},3.0f };
}

void Rize::update(float deltaTime)
{
	// インプット更新
	input_.update();

	// 重力反映
	if (m_position.y > 0.0f&&m_state != PlayerStateName::Jump)
	{
		m_velocity.y += parameters_.Get_Gravity() * deltaTime;
		m_position += m_velocity * deltaTime;
	}

	// ロックオン判定
	lockOnCheck();

	// 状態ごとの更新処理
	playerActions_[m_state].update(
		deltaTime, m_position, m_velocity, m_prevposition, m_rotation, get_pose(),
		m_motion, m_cameraRoate);

	// 乳揺れ
	oppai_yure(m_position, 10.0f, 0.75f, 30.0f);

	// 状態タイマー更新
	parameters_.Add_StateTimer(1.0f*deltaTime);

	// 次の状態のフラグチェック
	if (playerActions_[m_state].Get_NextActionFlag())
	{
		playerActions_[m_state].NextAction(m_state, parameters_);
		playerActions_[m_state].initialize();
	}

	// モーション変更
	mesh_.change_motion(m_motion);

	// アニメーションの終了時間設定
	parameters_.Set_EndTime(mesh_.get_motion_end_time());

	// アニメーション更新
	mesh_.update(deltaTime);
	mesh_.transform(get_pose());
	mesh_.transform(get_pose(), 120, m_pi);
	mesh_.transform(get_pose(), 126, m_pi);

	// ブレンドシェイプ更新
	shape_.update(m_state);

	// ダウンしたかの設定
	set_IsDown(parameters_.Get_IsDown());

	// キャラクターとステージのコリジョン
	CollisionMesh::collide_capsule(
		m_position + Vector3{ 0.0f,3.0f,0.0f },
		m_position + Vector3{ 0.0f,20.0f,0.0f },
		3.0f, &m_position);
	m_position = Vector3::Clamp(m_position, Vector3{ -165.0f,0.0f,-550.0f }, Vector3{ 173.0f,100.0f,570.0f });

	auto l_camera1 = world_->get_camera_rize();
	if (l_camera1 == nullptr)return;
	m_cameraRoate = l_camera1->get_pose();
}

void Rize::draw() const
{
	mesh_.draw();
	draw_weapon();

	// ロックオンエリアUIの描画
	if (m_gameMode == 0)
	{
		if (!parameters_.Get_IsLockOn())
		{
			if (m_numPlayer == 1)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff, Vector2::Zero);
			else if (m_numPlayer == 2)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff, Vector2{ 640.0f,0.0f });
		}
		else
		{
			if (m_numPlayer == 1)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn, Vector2::Zero);
			else if (m_numPlayer == 2)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn, Vector2{ 640.0f,0.0f });
		}
	}
	else
	{
		if (!parameters_.Get_IsLockOn())
		{
			if (m_numPlayer == 1)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff_4, Vector2::Zero);
			else if (m_numPlayer == 2)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff_4, Vector2{ 640.0f,0.0f });
			else if (m_numPlayer == 3)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff_4, Vector2{ 0.0f,360.0f });
			else if (m_numPlayer == 4)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOff_4, Vector2{ 640.0f,360.0f });
		}
		else
		{
			if (m_numPlayer == 1)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn_4, Vector2::Zero);
			else if (m_numPlayer == 2)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn_4, Vector2{ 640.0f,0.0f });
			else if (m_numPlayer == 3)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn_4, Vector2{ 0.0f,360.0f });
			else if (m_numPlayer == 4)
				Graphics2D::draw_sprite((int)SpriteID::LockOnAreaOn_4, Vector2{ 640.0f,360.0f });
		}
	}

	// HPゲージUIの描画
	if (m_numPlayer == 1)
	{
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpFrame,
			Vector2{ 47.5f,27.0f }, 0, 0, 1040, 110, Vector2::Zero, Vector2{ 0.3f,0.3f });
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpGauge,
			Vector2{ 50.0f,30.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });
	}
	else if (m_numPlayer == 2)
	{
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpFrame,
			Vector2{ 687.5f,27.0f }, 0, 0, 1040, 110, Vector2::Zero, Vector2{ 0.3f,0.3f });
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpGauge,
			Vector2{ 690.0f,30.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });
	}
	else if (m_numPlayer == 3)
	{
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpFrame,
			Vector2{ 47.5f,387.0f }, 0, 0, 1040, 110, Vector2::Zero, Vector2{ 0.3f,0.3f });
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpGauge,
			Vector2{ 50.0f,390.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });
	}
	else if (m_numPlayer == 4)
	{
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpFrame,
			Vector2{ 687.5f,387.0f }, 0, 0, 1040, 110, Vector2::Zero, Vector2{ 0.3f,0.3f });
		Graphics2D::draw_sprite_RCS(
			(int)SpriteID::HpGauge,
			Vector2{ 690.0f,390.0f }, 0, 0, (1020 / parameters_.Get_MaxHP())*parameters_.Get_HP(),
			90, Vector2::Zero, Vector2{ 0.3f,0.3f });
	}
}

void Rize::react(Actor & other)
{
	if (parameters_.Get_HP() > 0)
	{
		// 攻撃を受けた時
		if (other.get_name() == "Attack")
		{
			input_.Vibration(500, 200);

			Sound::play_se((int)SoundID_SE::Rize_Damage);
			m_motion = (int)RizeAnmID::Damage;
			m_state = PlayerStateName::Damage;
			playerActions_[m_state].initialize();
			parameters_.Set_StateTimer(0.0f);
			mesh_.change_motion_same(m_motion);
			parameters_.Damage_HP(1);

			if (parameters_.Get_HP() <= 0)
			{
				Sound::play_se((int)SoundID_SE::Rize_Down);
				m_motion = (int)RizeAnmID::Down;
				m_state = PlayerStateName::Down;
				playerActions_[m_state].initialize();
				parameters_.Set_StateTimer(0.0f);
				return;
			}

			return;
		}

		// ブレイク攻撃を受けた時
		else if (other.get_name() == "BreakAttack")
		{
			input_.Vibration(600, 200);

			Sound::play_se((int)SoundID_SE::Rize_Damage);
			m_motion = (int)RizeAnmID::DamageBreak;
			m_state = PlayerStateName::DamageBreak;
			playerActions_[m_state].initialize();
			parameters_.Set_BreakDirection(other.get_pose().Forward());
			parameters_.Set_StateTimer(0.0f);
			parameters_.Damage_HP(2);

			if (parameters_.Get_HP() <= 0)
			{
				Sound::play_se((int)SoundID_SE::Rize_Down);
				m_motion = (int)RizeAnmID::Down;
				m_state = PlayerStateName::Down;
				playerActions_[m_state].initialize();
				parameters_.Set_StateTimer(0.0f);
				return;
			}

			return;
		}
	}
	m_position = Vector3(m_prevposition.x, m_position.y, m_prevposition.z);
}

void Rize::handle_message(EventMessage message, void * param)
{
}

// 武器描画
void Rize::draw_weapon() const
{
	StaticMesh::bind(m_weapon);
	StaticMesh::transform(mesh_.get_bone_matrix(85));
	StaticMesh::draw();
}

// 乳揺れ
void Rize::oppai_yure(const Vector3 & l_rest_position, float l_stiffness, float l_friction, float l_mass)
{
	const Vector3 stretch = m_pi - l_rest_position;
	const Vector3 force = -l_stiffness * stretch;
	const Vector3 acceleration = force / l_mass;
	m_piVelo = l_friction * (m_piVelo + acceleration);
	m_pi += m_piVelo;
}

// ロックオン判定
void Rize::lockOnCheck()
{
	auto l_chiya = world_->find_actor(ActorGroup::Chiya, "Chiya");
	auto l_syaro = world_->find_actor(ActorGroup::Syaro, "Syaro");
	auto l_cocoa = world_->find_actor(ActorGroup::Cocoa, "Cocoa");

	if (m_gameMode == 0)
	{
		if (l_chiya != nullptr)
		{
			parameters_.Set_LockOnDirection(l_chiya->get_position() - m_position);
			parameters_.Set_DistanceNear(Vector3::Distance(m_position, l_chiya->get_position()));
		}
		if (l_syaro != nullptr)
		{
			parameters_.Set_LockOnDirection(l_syaro->get_position() - m_position);
			parameters_.Set_DistanceNear(Vector3::Distance(m_position, l_syaro->get_position()));
		}
		if (l_cocoa != nullptr)
		{
			parameters_.Set_LockOnDirection(l_cocoa->get_position() - m_position);
			parameters_.Set_DistanceNear(Vector3::Distance(m_position, l_cocoa->get_position()));
		}
	}
	else
	{
		parameters_.Set_DistanceToChiya(Vector3::Distance(m_position, l_chiya->get_position()));
		parameters_.Set_DistanceToSyaro(Vector3::Distance(m_position, l_syaro->get_position()));
		parameters_.Set_DistanceToCocoa(Vector3::Distance(m_position, l_cocoa->get_position()));

		if (parameters_.Get_DistanceToChiya() < parameters_.Get_DistanceToSyaro())
		{
			if (parameters_.Get_DistanceToChiya() < parameters_.Get_DistanceToCocoa())
			{
				parameters_.Set_LockOnDirection(l_chiya->get_position() - m_position);
				parameters_.Set_DistanceNear(parameters_.Get_DistanceToChiya());
			}
			else if (parameters_.Get_DistanceToCocoa() < parameters_.Get_DistanceToChiya())
			{
				parameters_.Set_LockOnDirection(l_cocoa->get_position() - m_position);
				parameters_.Set_DistanceNear(parameters_.Get_DistanceToCocoa());
			}
		}
		else if (parameters_.Get_DistanceToSyaro() < parameters_.Get_DistanceToChiya())
		{
			if (parameters_.Get_DistanceToSyaro() < parameters_.Get_DistanceToCocoa())
			{
				parameters_.Set_LockOnDirection(l_syaro->get_position() - m_position);
				parameters_.Set_DistanceNear(parameters_.Get_DistanceToSyaro());
			}
			else if (parameters_.Get_DistanceToCocoa() < parameters_.Get_DistanceToSyaro())
			{
				parameters_.Set_LockOnDirection(l_cocoa->get_position() - m_position);
				parameters_.Set_DistanceNear(parameters_.Get_DistanceToCocoa());
			}
		}
	}
	parameters_.LockOnDirectionNormlize();
	m_forward = m_cameraRoate.Forward();
	m_forward.Normalize();

	if (parameters_.Get_DistanceNear() > 100.0f
		|| Vector3::Dot(m_forward, parameters_.Get_LockOnDirection())
		< (0.9f - ((100.0f - parameters_.Get_DistanceNear()) / 500.0f)))
	{
		parameters_.LockOn(false);
		return;
	}

	else if (Vector3::Dot(m_forward, parameters_.Get_LockOnDirection())
		>= (0.9f - ((100.0f - parameters_.Get_DistanceNear()) / 500.0f)))
	{
		parameters_.LockOn(true);
	}
}
