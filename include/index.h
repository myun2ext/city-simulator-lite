#ifndef __github_com_myun2__city_simulator__index__H__
#define __github_com_myun2__city_simulator__index__H__

#include <stdlib.h>
#include <memory.h>
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
	unsigned int alloc_size = initial_size * sizeof(index_item_t);

	i->residencials = malloc(alloc_size);
	i->commercials = malloc(alloc_size);
	i->industrials = malloc(alloc_size);
	i->roads = malloc(alloc_size);
	i->rails = malloc(alloc_size);
	i->administratives = malloc(alloc_size);

	memset(i->residencials, 0xffffffff, alloc_size);
	memset(i->commercials, 0xffffffff, alloc_size);
	memset(i->industrials, 0xffffffff, alloc_size);
	memset(i->roads, 0xffffffff, alloc_size);
	memset(i->rails, 0xffffffff, alloc_size);
	memset(i->administratives, 0xffffffff, alloc_size);
}

inline void append_road_index(unsigned int x, unsigned int y)
{

}

#endif//__github_com_myun2__city_simulator__index__H__
