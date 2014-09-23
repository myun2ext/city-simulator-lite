#include <stdio.h>
#include "city.h"

city g_city;

int main()
{
	init_city(&g_city, "Example City.", 5, 5);
	return 0;
}