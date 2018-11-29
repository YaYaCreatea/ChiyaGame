#ifndef _RANDOM_H_
#define _RANDOM_H_

class Random
{
public:

	//—”¶¬Ší‚Ì‰Šú‰»
	static void randomize();

	//—”¶¬Ší‚Ì‰Šú‰»(ˆø”‚ ‚è)
	static void randomize(unsigned int seed);

	//intŒ^‚Ì—”‚ğ‹‚ß‚é
	static int rand(int low,int high);

	//floatŒ^‚Ì—”‚ğ‹‚ß‚é
	static float rand(float low,float high);

	//—”‚ÌƒV[ƒh‚ğæ“¾
	static unsigned int seed();

};

#endif