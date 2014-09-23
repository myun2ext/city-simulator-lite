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
	char name[256];

	unsigned int population;
} city;

inline void init_city(city *c, const char* name, unsigned int width, unsigned int height)
{
	unsigned int i;
	c->width = width;
	c->height = height;
	c->blocks = (block_type*)calloc(sizeof(block_t), width * height);
	strcpy(c->name, name);

	//	Init blocks
	for(i=0; i<width * height; i++)
		init_block(&c->blocks[i]);
}

#endif//__github_com_myun2__city_simulator__city__H__
