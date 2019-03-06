#ifndef _ANIMATED_BLEND_SHAPE_H_
#define _ANIMATED_BLEND_SHAPE_H_

#include "../Character/Player/PlayerStateName.h"

//ブレンドシェイブアニメーション
class AnimatedBlendShape
{
public:
	//コンストラクタ
	AnimatedBlendShape(int l_model);

	//更新(状態設定)
	void update(PlayerStateName l_state);

	//更新(タイマー設定)
	void update(float l_timer, float l_cut0, float l_cut1 = 0.0f);

private:

	//状態ごとのシェイプ更新
	void StateFaceUpdate(PlayerStateName l_state);

	//タイマーでのシェイプ更新
	void TimerFaceUpdate(float l_timer, float l_cut0, float l_cut1 = 0.0f);

	//値設定(攻撃,ダメージ)
	void Set_ShapeRate(float l_attackRate, float l_damageRate);

	//値設定(攻撃,ダメージ,笑顏)
	void Set_ShapeRate(float l_attackRate, float l_damageRate,float l_smileRate);

	//シェイプアニメーション
	void FaceAnimation();

private:
	int m_model;
	float m_shapeRateAttack;
	float m_shapeRateDamage;
	float m_shapeRateSmile;
};

#endif