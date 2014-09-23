#ifndef __github_com_myun2__city_simulator__block__H__
#define __github_com_myun2__city_simulator__block__H__

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
	unsigned int density;
} block, block_t, block_type;

inline void init_block(block* b)
{
}

void inhabit(block *b, unsigned int peoples)
{
	b->population += peoples;
	b->value += peoples;
}

#endif//__github_com_myun2__city_simulator__block__H__
