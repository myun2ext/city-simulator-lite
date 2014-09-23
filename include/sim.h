#ifndef __github_com_myun2__city_simulator__sim__H__
#define __github_com_myun2__city_simulator__sim__H__

#include "city.h"
#include "random.h"

void vary_population(city* s)
{
	int ups = rand() % 3 + s->population * 0.03 / 12;
	int block_n = rand() % (s->width * s->height);
	
	s->population += ups;
	inhabit(&s->blocks[block_n], ups);
}

void city_simulation_step(city* s)
{
	vary_population(s);
	s->budget += revenue(s);
	s->month += 1;
}

#endif//__github_com_myun2__city_simulator__sim__H__
