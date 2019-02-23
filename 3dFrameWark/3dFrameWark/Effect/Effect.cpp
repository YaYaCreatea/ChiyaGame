#include "Effect.h"
#include <EffekseerForDXLib.h>

//バインド中のテクスチャ
int Effect::efk_{ -1 };
//テクスチャアセット
EffectAsset Effect::effect_;

void Effect::initialize()
{
	finalize();
}

void Effect::finalize()
{
	effect_.clear();
	efk_ = -1;
}

bool Effect::load(int id, const std::string & file_name)
{
	return effect_.load(id, file_name);
}

void Effect::erase(int id)
{
	efk_ = (efk_ == effect_[id]) ? -1 : efk_;
	effect_.erase(id);
}

void Effect::update()
{
	//UpdateEffekseer3D();
	
}

void Effect::alphaFead(float l_alpha)
{
	MV1SetOpacityRate(efk_, l_alpha / 60.0f);
}

void Effect::play(int id,const Vector3 & position, float pitch, float yaw, float roll)
{
	//SetPosPlayingEffekseer3DEffect(efk_, position.x, position.y, position.z);
	//SetPosPlayingEffekseer3DEffect(effect_[id], position.x, position.y, position.z);
	//SetRotationPlayingEffekseer3DEffect(efk_, pitch, yaw, roll);
}

void Effect::bind(int id)
{
	//efk_ = PlayEffekseer3DEffect(effect_[id]);
	//PlayEffekseer3DEffect(effect_[id]);

	efk_ = effect_[id];
}

void Effect::draw()
{
	//DrawEffekseer3D();

	MV1DrawModel(efk_);
}

void Effect::transform(const Vector3& l_position,const Matrix & l_matrix, float l_pitch, float l_yaw)
{
	MV1SetMatrix(
		efk_,
		Matrix(l_matrix*
			Matrix::CreateFromAxisAngle(l_matrix.Forward(), l_pitch)*
			Matrix::CreateFromAxisAngle(Vector3::Up, l_yaw)).Translation(l_position));
}

int Effect::get_effect(int id)
{
	return effect_[id];
}
