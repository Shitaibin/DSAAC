#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
	int * t = a;
	a = b;
	b = t;
}

int RandInt(const int b, const int e)
{
	srand(clock());
	return rand()%(e-b) + b;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	int* A = (int *)malloc(sizeof(int) * n);
		

	for (int i = 0;i < n; i++)
	{
		A[i] = RandInt(-5, 5);	
	}

	return 0;
}










