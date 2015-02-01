#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;	
	scanf("%d", &n);
	unsigned int seed = time(0);
	printf("%d\n", n);
	while(n-- >0)
	{
		printf("%d\n", rand());
	}

	return 0;
}
