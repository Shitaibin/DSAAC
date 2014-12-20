#include "queue.h"

int main()
{
	int L, N, M;
	scanf("%d", &L);

	Queue Q = CreateQueue(L);
	if (Q == NULL)
	{
		FatalError("Create queue failed");
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
			Enqueue(e, Q);
		}

		scanf("%d", &M);
		while (M-- > 0)
			Dequeue(Q);

	}

	int end = (int)clock();
	int ticks = end-sta;
	
	printf("ArrayQueue\t%d\n", ticks);
//	printf("Current Front: %c\n", Front(Q));

 	DisposeQueue(Q);	
	return 0;
}







