
/**
 * using liner algorithm to get the maximum
 * subsequence sum of a list.
 */





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

int MaxSubsequenceSum ( const int A[], int N)
{
	int MaxSum, i, CurSum;

	MaxSum = 0; 
	CurSum = 0;
	for (i =0; i < N; i++)
	{
		CurSum += A[i];

		if (CurSum < 0)
			CurSum = 0;
		else if (CurSum > MaxSum)
			MaxSum = CurSum;
	}

	return MaxSum;

}


int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	int* A = (int *)malloc(sizeof(int) * n);
		

	for (int i = 0;i < n; i++)
	{
		A[i] = RandInt(-5, 5);	
	}

	int sta = (int) clock();	
	int MaxSum = MaxSubsequenceSum(A, n);
	int end = (int) clock();	

	int dur = end - sta;

	printf("test size \t MaxSum \t clicks\n");
	printf("%d \t\t %d \t\t %d\n", n, MaxSum, dur);

	return 0;
}










