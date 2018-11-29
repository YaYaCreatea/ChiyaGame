#include "Random.h"
#include <random>

//乱数生成器
static std::mt19937 mt;

//乱数のシード
static unsigned int s_seed{ std::mt19937::default_seed };

//乱数生成器の初期化
void Random::randomize()
{
	std::random_device rd;
	randomize(rd());
}

//乱数生成器の初期化(引数あり)
void Random::randomize(unsigned int seed)
{
	s_seed = seed;
	mt = std::mt19937(s_seed);
}

//int型の乱数を求める
int Random::rand(int low, int high)
{
	std::uniform_int_distribution<int> dist(low, high);
	return dist(mt);
}

//float型の乱数を求める
float Random::rand(float low, float high)
{
	std::uniform_real_distribution<float> dist(low, high);
	return dist(mt);
}

//乱数のシードを取得
unsigned int Random::seed()
{
	return s_seed;
}
