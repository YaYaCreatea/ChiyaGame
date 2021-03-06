#include "SkyBox.h"
#include <DxLib.h>

//バインド中のモデル
int SkyBox::model_{ -1 };
//モデルアセット
ModelAsset SkyBox::asset_;

//初期化
void SkyBox::initialize()
{
	finalize();
}

//終了処理
void SkyBox::finalize()
{
	asset_.clear();
	model_ = -1;
}

//読み込み
bool SkyBox::load(int id, const std::string & file_name)
{
	return asset_.load(id, file_name);
}

//削除
void SkyBox::erase(int id)
{
	model_ = (model_ == asset_[id]) ? -1 : model_;
	asset_.erase(id);
}

//メッシュのバインド
void SkyBox::bind(int id)
{
	model_ = asset_[id];
}

//描画
void SkyBox::draw()
{
	//視野変換行列の取得
	MATRIX view_matrix = GetCameraViewMatrix();

	//視野変換行列の平行移動量をクリア
	MATRIX skybox_matrix = view_matrix;
	skybox_matrix.m[3][0] = 0.0f;
	skybox_matrix.m[3][1] = 0.0f;
	skybox_matrix.m[3][2] = 0.0f;

	//視野変換行列の設定
	SetCameraViewMatrix(skybox_matrix);

	//ライティングを無効にする
	SetUseLighting(FALSE);

	//Zバッファに書き込みを行わない
	MV1SetWriteZBuffer(model_, FALSE);

	//モデルの表示
	MV1DrawModel(model_);

	//視野変換を元に戻す
	SetCameraViewMatrix(view_matrix);

	//ライティングを有効にする
	SetUseLighting(TRUE);
}
