#include <stdio.h>
#include <stdlib.h>



int BS( const int A[], int X, int N)
{
	int l = 0, h = N-1, mid;

	while (l < h)
	{
		mid = (l+h)/2;
		if (X <= A[mid])
			h = mid;
		else 
			l = mid+1;
	}

	return l;
}


int main()
{
	int n;
	scanf("%d", &n);


	int *A = malloc(sizeof(int) * n);
	int i;

	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	int x;
	scanf("%d", &x);

	int index = BS(A, x, n);
	printf("%d %d\n", x, A[index]);

	return 0;
}




