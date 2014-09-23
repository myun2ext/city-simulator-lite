#include <stdio.h>
#include <locale.h>
#include "sim.h"

city g_city;

int main()
{
	const int size = 8;
	char citydate[8];
	int i = 0;

	init_city(&g_city, "Example City.", "myun2", 100000, size, size);
	printf("Initialized city. %s\n", g_city.name);
	build(blk_road, &g_city, 3, 3);

	for(i=0; i<1000; i++)
	{
		city_simulation_step(&g_city);
	}
	setlocale(LC_ALL, "");
	city_date(&g_city, citydate);
	printf("Date: %s\n", citydate);
	printf("City population: %d\n", g_city.population);
	printf("City budget: %d\n",     g_city.budget);

	return 0;
}