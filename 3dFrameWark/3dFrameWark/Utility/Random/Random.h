#ifndef _RANDOM_H_
#define _RANDOM_H_

class Random
{
public:

	//����������̏�����
	static void randomize();

	//����������̏�����(��������)
	static void randomize(unsigned int seed);

	//int�^�̗��������߂�
	static int rand(int low,int high);

	//float�^�̗��������߂�
	static float rand(float low,float high);

	//�����̃V�[�h���擾
	static unsigned int seed();

};

#endif