#include <stdio.h>
#include <stdlib.h>


int FastPow( int x, int n,int *count)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	int res = 1;
	while (n > 0)
	{
		(*count)++;

		if (n%2 == 0)
		{
			x *= x;
			n = n/2;
		}
		else 
		{
			res *= x;
			x *= x;
			n = n/2;
		}
	}

	return res;
}


int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int count = 0;
	int res = FastPow(a, b, &count);

	printf("%d\n", res);
	
	printf("count = %d\n", count); 
	return 0;
}













