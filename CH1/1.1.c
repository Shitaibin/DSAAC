#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int cmp(const void* a, const void *b)
{
	return *(int*)a - *(int*)b;
} 

int main()
{
	int n;
	scanf("%d", &n);
	int a[SIZE];
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
	}
	
	qsort(a, n, sizeof(int), cmp);

	return 0;
}




