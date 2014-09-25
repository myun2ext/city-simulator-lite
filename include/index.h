#ifndef __github_com_myun2__city_simulator__index__H__
#define __github_com_myun2__city_simulator__index__H__

#include <stdlib.h>
#include "block.h"

typedef struct
{
	block* residencials;
	block* commercials;
	block* industrials;
	block* roads;
	block* rails;
	block* administratives;
} index_t, index;

inline void init_index(index *i, unsigned int initial_size)
{
	i->residencials = calloc(initial_size, sizeof(block_type));
	i->commercials = calloc(initial_size, sizeof(block_type));
	i->industrials = calloc(initial_size, sizeof(block_type));
	i->roads = calloc(initial_size, sizeof(block_type));
	i->rails = calloc(initial_size, sizeof(block_type));
	i->administratives = calloc(initial_size, sizeof(block_type));
}

#endif//__github_com_myun2__city_simulator__index__H__
