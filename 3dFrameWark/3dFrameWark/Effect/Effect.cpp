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
	UpdateEffekseer3D();
}

void Effect::play(int id,const Vector3 & position, float pitch, float yaw, float roll)
{
	//SetPosPlayingEffekseer3DEffect(efk_, position.x, position.y, position.z);
	SetPosPlayingEffekseer3DEffect(effect_[id], position.x, position.y, position.z);
	//SetRotationPlayingEffekseer3DEffect(efk_, pitch, yaw, roll);
}

void Effect::bind(int id)
{
	//efk_ = PlayEffekseer3DEffect(effect_[id]);
	PlayEffekseer3DEffect(effect_[id]);
}

void Effect::draw()
{
	DrawEffekseer3D();
}
