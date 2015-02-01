#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	clock_t b = clock();
	int i , c;	
	for (i = 0; i < 10000; i++)
		c = i * i;

	clock_t e = clock();

	int bi = (int)b;
	int ei = (int)e;

	int n = 3;
	
	printf("%d", ei);
	printf("%f", (float)n/ei);

	return 0;
}
