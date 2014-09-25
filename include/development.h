#ifndef __github_com_myun2__city_simulator__development__H__
#define __github_com_myun2__city_simulator__development__H__

#include "city.h"

inline unsigned int build_road(city *c, unsigned int x, unsigned int y, unsigned int stage)
{
	unsigned int cost = eviction_cost(&c->blocks[x + y*x]);
	if ( c->budget < cost )
		return 0;

	append_road_index(&c->index, x, y);
	return c->budget -= road(&c->blocks[x + y*x], stage);
}

#endif//__github_com_myun2__city_simulator__development__H__
