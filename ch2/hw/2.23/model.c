#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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


	return 0;
}




