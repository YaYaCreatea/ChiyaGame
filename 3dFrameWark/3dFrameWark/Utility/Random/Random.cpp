#include "Random.h"
#include <random>

//����������
static std::mt19937 mt;

//�����̃V�[�h
static unsigned int s_seed{ std::mt19937::default_seed };

//����������̏�����
void Random::randomize()
{
	std::random_device rd;
	randomize(rd());
}

//����������̏�����(��������)
void Random::randomize(unsigned int seed)
{
	s_seed = seed;
	mt = std::mt19937(s_seed);
}

//int�^�̗��������߂�
int Random::rand(int low, int high)
{
	std::uniform_int_distribution<int> dist(low, high);
	return dist(mt);
}

//float�^�̗��������߂�
float Random::rand(float low, float high)
{
	std::uniform_real_distribution<float> dist(low, high);
	return dist(mt);
}

//�����̃V�[�h���擾
unsigned int Random::seed()
{
	return s_seed;
}
