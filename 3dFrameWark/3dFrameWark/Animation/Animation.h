#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "../SkeletalMesh/SkeletalMesh.h"
#include <array>

class Animation
{
public:
	using Matrices = std::array<Matrix, 256>;

public:
	//コンストラクタ
	Animation(int l_model, int l_motion);

	//更新
	void update(float deltaTime);

	//モーション変更
	void change_motion(int l_motion);

	void change_motion_same(int l_motion);

	//現在再生中のモーション
	int get_current_motion();

	//変換行列を取得
	const Matrices& get_local_matrices()const;

	//ボーン数を取得
	int get_bone_count()const;

	//終了時間を取得
	float get_end_time()const;

private:
	const float LERPTIME{ 10.0f };	//補間フレーム数

	int m_model{ 0 };				//アニメーション番号
	int m_motion{ 0 };				//再生中のモーション番号
	float m_motionTimer{ 0.0f };	//再生中のアニメーションタイマ

	int m_prev_motion{ 0 };				//前回再生したモーション番号
	float m_prev_motionTimer{ 0.0f };	//前回再生した最終アニメーションタイマ

	float m_lerpTimer{ 0.0f };		//補間アニメーションタイマ

	Matrices m_local_matrices;		//アニメーション変換行列
};

#endif