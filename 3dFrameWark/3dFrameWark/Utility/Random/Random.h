#ifndef _RANDOM_H_
#define _RANDOM_H_

class Random
{
public:

	//乱数生成器の初期化
	static void randomize();

	//乱数生成器の初期化(引数あり)
	static void randomize(unsigned int seed);

	//int型の乱数を求める
	static int rand(int low,int high);

	//float型の乱数を求める
	static float rand(float low,float high);

	//乱数のシードを取得
	static unsigned int seed();

};

#endif