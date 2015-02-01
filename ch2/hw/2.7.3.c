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
		
	clock_t sta = clock();

	for (int i = 0;i < n; i++)
	{
		A[i] = i+1;
	}

	for (int i = 1;i < n; i++)
		Swap(&A[i], &A[RandInt(0, i)]);

	clock_t end = clock();		
	int div = (int)end-(int)sta;
	printf("%d \t%d \t%d\n", n, div, div/n);
	return 0;
}










