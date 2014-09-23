#ifndef __github_com_myun2__city_simulator__city__H__
#define __github_com_myun2__city_simulator__city__H__

#include <stdlib.h>
#include <string.h>
#include "block.h"

typedef struct
{
	unsigned int width;
	unsigned int height;
	block_t *blocks;
	char name[128];
	char mayor_name[64];
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

#endif//__github_com_myun2__city_simulator__city__H__
