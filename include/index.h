#ifndef __github_com_myun2__city_simulator__index__H__
#define __github_com_myun2__city_simulator__index__H__

#include <stdlib.h>
#include <memory.h>
#include "block.h"
#include "random.h"

typedef struct
{
	unsigned int x;
	unsigned int y;
} index_item_t, index_item;

typedef struct
{
	index_item_t* residencials;
	index_item_t* commercials;
	index_item_t* industrials;
	index_item_t* roads;
	index_item_t* rails;
	index_item_t* administratives;

	unsigned int residencial_count;
	unsigned int commercial_count;
	unsigned int industrial_count;
	unsigned int road_count;
	unsigned int rail_count;
	unsigned int administrative_count;
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

	i->residencial_count = 0;
	i->commercial_count = 0;
	i->industrial_count = 0;
	i->road_count = 0;
	i->rail_count = 0;
	i->administrative_count = 0;
}

inline void append_road_index(index *i, unsigned int x, unsigned int y)
{
	index_item *p = i->roads;

	for(; p->x != 0xffffffff; p++)
	{
		if ( p->x == x && p->y == y )
			return;
	}
	p->x = x; p->y = y;
	i->road_count++;
}

index_item random_select_road(index *i)
{
	unsigned int r = sim_rand() % i->road_count;
	return i->roads[r];
}

#endif//__github_com_myun2__city_simulator__index__H__
