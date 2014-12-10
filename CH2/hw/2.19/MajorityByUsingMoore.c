#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int Majority( int A[], int N)
{
	int maj_index = 0, count = 0;

	int i;
	for(i = 0; i < N; i++)
	{
		if (count == 0)
		{
			maj_index = i;
			count = 1;
		}
		else
		{	
			if (A[maj_index] == A[i])
				count++;
			else
				count--;
		}	
	}

	return maj_index;
}


int main()
{
	int n;
	scanf("%d", &n);

	int *A = malloc(sizeof(int) * n);

	printf("%d ", n);

	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
		printf("%d ", A[i]);
	}
	
	int sta = (int) clock();
	int index = Majority(A, n);
	
	int count = 0;
	for(i = 0; i < n; +i++)
	{
		if (A[i] == A[index])
			count++;
	}

	int end = (int) clock();

	if (count > n/2)
	//	printf(" -> %d \t %f\n", A[index], (float)n/(end-sta));
		printf(" -> %d \t %d %d %d\n", A[index], end, sta, n/(end-sta));
	else
		printf(" -> none \t %f\n", (float)n/(end-sta));

	return 0;
}
		
			

