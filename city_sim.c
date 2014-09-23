#include <stdio.h>
#include "sim.h"

city g_city;

int main()
{
	const int size = 3000;
	int i = 0;

	init_city(&g_city, "Example City.", size, size);
	printf("Initialized city. %s\n", g_city.name);

	for(i=0; i<1000; i++)
	{
		city_simulation_step(&g_city);
	}
	printf("City population: %d\n", g_city.population);

	return 0;
}