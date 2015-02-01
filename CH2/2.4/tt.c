#include <stdio.h>

int main()
{
	int i ;

	for (i = 0; i < 5; i++)
	{
		if(i >> 1)
			printf("i >> 1\n");
		else
			printf("no");
	}

	return 0;
}
