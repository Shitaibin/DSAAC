#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int main()
{
	int L, N, M;
	scanf("%d", &L);

	Stack S = Create(L);
	if (S == NULL)
	{
		FatalError("Create stack failed");
		exit(1);
	}

	int sta = (int)clock();	
	while(scanf("%d", &N) != EOF)
	{
		int i;
		ElementType e;	
		for (i=0; i<N; i++)
		{
			getchar();	
			scanf("%c", &e);
			Push(e, S);
		}

		scanf("%d", &M);
		while (M-- > 0)
			Pop(S);

	}

	int end = (int)clock();
	int ticks = end-sta;
	
	printf("ArrayStack\t%d\n", ticks);

 	Dispose(S);	
	return 0;
}







