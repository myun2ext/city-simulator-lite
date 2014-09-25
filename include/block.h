#ifndef __github_com_myun2__city_simulator__block__H__
#define __github_com_myun2__city_simulator__block__H__

#include <math.h>
#include <memory.h>

typedef unsigned int u_int;
enum area_type_e
{
	wild_blk,
	blk_residencial,
	blk_commercial,
	blk_industrial,
	blk_road=70,
	blk_rail,
	blk_administrative = 99
};

enum build_type_e
{
	bld_road,
	bld_rail
};

typedef struct
{
	enum area_type_e area_type;
	unsigned int detail_type1;
	unsigned int detail_type2;
	unsigned int detail_type3;
	unsigned int population;
	unsigned int stage;
	unsigned int value;
	unsigned int age;
	char name[64];
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
	if ( b->area_type != wild_blk && b->area_type != blk_residencial )
		return 0;

	b->area_type = blk_residencial;
	b->population += peoples;
	b->value += peoples;
	return b->population;
}

inline unsigned int eviction_cost(block *b)
{
	return b->population * 3;
}

inline unsigned int eviction(block *b)
{
	unsigned int cost = eviction_cost(b);
	b->population = 0;
	return cost;
}

inline unsigned int road(block *b, unsigned int stage)
{
	unsigned int cost = 20 * (stage + 1);
	cost += eviction(b);
	b->area_type = blk_road;
	b->value = 1;
	return cost;
}

inline unsigned int rail(block *b, unsigned int stage)
{
	unsigned int cost = 40 * (stage + 1);
	cost += eviction(b);
	b->area_type = blk_rail;
	b->value = 7;
	return cost;
}

#endif//__github_com_myun2__city_simulator__block__H__
