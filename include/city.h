#ifndef __github_com_myun2__city_simulator__city__H__
#define __github_com_myun2__city_simulator__city__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "block.h"

typedef struct
{
	unsigned int width;
	unsigned int height;
	block_t *blocks;
	char name[128];
	char mayor_name[64];
	unsigned int month;
	unsigned int budget;

	unsigned int population;
} city;

inline void init_city(city *c, const char* name, const char* mayor, unsigned int budget, unsigned int width, unsigned int height)
{
	unsigned int i;

	c->width = width;
	c->height = height;
	c->blocks = (block_type*)calloc(sizeof(block_t), width * height);
	strcpy(c->name, name);
	strcpy(c->mayor_name, mayor);
	c->budget = budget;

	//	Init blocks
	for(i=0; i<width * height; i++)
		init_block(&c->blocks[i]);
}

inline unsigned int revenue(city *c) {
	return c->population * 3;
}

inline unsigned int build(enum area_type_e type, city *c, unsigned int x, unsigned int y)
{
	unsigned int cost = eviction_cost(&c->blocks[x + y*x]);
	if ( c->budget < cost )
		return 0;
	return c->budget -= road(&c->blocks[x + y*x]);
}

void city_date(city* c, char* s)
{
	unsigned int month = c->month;
	sprintf(s, "%04d/%d", 1900 + month / 12, month % 12 + 1);
}

#endif//__github_com_myun2__city_simulator__city__H__
