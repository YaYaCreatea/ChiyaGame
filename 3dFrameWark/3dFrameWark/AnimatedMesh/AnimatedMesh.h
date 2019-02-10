#ifndef _ANIMATED_MESH_H_
#define _ANIMATED_MESH_H_

#include "../SkeletalMesh/SkeletalMesh.h"
#include "../Animation/Animation.h"
#include <array>

class AnimatedMesh
{
public:
	using BoneMatrices = std::array<Matrix, 256>;

public:
	//コンストラクタ
	AnimatedMesh(int l_mesh, int l_motion = 0);

	//更新
	void update(float deltaTime);

	//描画
	void draw()const;

	//モーション変更
	void change_motion(int l_motion);

	void change_motion_same(int l_motion);

	//スケルトンの変換行列を計算する
	void transform(const Matrix& l_world);

	//スケルトンの変換行列を計算する
	void transform(const Matrix& l_world,int l_no, Vector3 m_pi);

	//変換行列を取得
	const Matrix& get_bone_matrix(int l_no)const;

	//モーションの終了時間を取得
	float get_motion_end_time()const;

private:
	int m_mesh;						//メッシュ

	Animation animation_;			//アニメーション

	BoneMatrices m_world_matrices;	//スケルトン変換行列
};

#endif