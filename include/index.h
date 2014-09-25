#ifndef __github_com_myun2__city_simulator__index__H__
#define __github_com_myun2__city_simulator__index__H__

#include <stdlib.h>
#include "block.h"

typedef struct
{
	unsigned int x;
	unsigned int y;
} index_item_t;

typedef struct
{
	index_item_t* residencials;
	index_item_t* commercials;
	index_item_t* industrials;
	index_item_t* roads;
	index_item_t* rails;
	index_item_t* administratives;
} index_t, index;

inline void init_index(index *i, unsigned int initial_size)
{
	i->residencials = calloc(initial_size, sizeof(index_item_t));
	i->commercials = calloc(initial_size, sizeof(index_item_t));
	i->industrials = calloc(initial_size, sizeof(index_item_t));
	i->roads = calloc(initial_size, sizeof(index_item_t));
	i->rails = calloc(initial_size, sizeof(index_item_t));
	i->administratives = calloc(initial_size, sizeof(index_item_t));
}

#endif//__github_com_myun2__city_simulator__index__H__
