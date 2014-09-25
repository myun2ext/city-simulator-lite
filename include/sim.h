#ifndef __github_com_myun2__city_simulator__sim__H__
#define __github_com_myun2__city_simulator__sim__H__

#include "city.h"
#include "random.h"

unsigned int employment(city* s, unsigned int peoples)
{
	int block_n = rand() % (s->width * s->height);
	block_type *b = &s->blocks[block_n];

	if ( b->area_type != wild_blk && b->area_type != blk_commercial && b->area_type != blk_industrial )
		return 0;

	b->area_type = blk_commercial;
	return b->population += peoples;
}

block* nearly_road_resident(city* s)
{
	index_item i = random_select_road(&s->index);
	int x = i.x;
	int y = i.y;
	unsigned int n = sim_rand() % 4;
	switch(n)
	{
	case 0:
		x--; break;
	case 1:
		x++; break;
	case 2:
		y--; break;
	case 3:
		y++; break;
	}
	if ( x < 0 || y < 0 )
		return nearly_road_resident(s);
	return &s->blocks[x + y*x];
}

void sim_resident(city* s)
{
	int ups = rand() % 3 + s->population * 0.03 / 12;
	int block_n = rand() % (s->width * s->height);
	
	s->population += ups;
	inhabit(&s->blocks[block_n], ups);
	employment(s, ups * 0.45);
}

void city_simulation_step(city* s)
{
	sim_resident(s);
	s->budget += revenue(s);
	s->month += 1;
}

#endif//__github_com_myun2__city_simulator__sim__H__
