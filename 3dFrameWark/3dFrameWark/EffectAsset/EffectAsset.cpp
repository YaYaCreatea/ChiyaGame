#include "EffectAsset.h"
#include <EffekseerForDXLib.h>

EffectAsset::EffectAsset()
{
}

EffectAsset::~EffectAsset()
{
	clear();
}

bool EffectAsset::load(int id, const std::string & file_name)
{
	erase(id);
	effect_[id] = LoadEffekseerEffect(file_name.c_str());
	return effect_[id] != -1;
}

void EffectAsset::erase(int id)
{
	if (effect_.count(id) > 0)
	{
		DeleteEffekseerEffect(effect_[id]);
		effect_.erase(id);
	}
}

void EffectAsset::clear()
{
	for (const auto effect : effect_)
		DeleteEffekseerEffect(effect.second);

	effect_.clear();
}

int EffectAsset::operator[](int id) const
{
	return effect_.at(id);
}