#ifndef __github_com_myun2__city_simulator__block__H__
#define __github_com_myun2__city_simulator__block__H__

#include <math.h>

typedef unsigned int u_int;
enum area_type_e
{
	none,
	residence,
	commercial,
	industrial,
	administrative	
};

typedef struct
{
	enum area_type_e area_type;
	unsigned int value;
	unsigned int population;
	unsigned int stage;
} block, block_t, block_type;

inline void init_block(block* b)
{
}

inline unsigned int max_population_in_staged(int stage)
{
	return pow(2, (stage+1)) * 20;
}

unsigned int inhabit(block *b, unsigned int peoples)
{
	unsigned int max = max_population_in_staged(b->stage);

	//if ( b->population + peoples > max )
	//	return 0;

	b->population += peoples;
	b->value += peoples;
	return b->population;
}

#endif//__github_com_myun2__city_simulator__block__H__
