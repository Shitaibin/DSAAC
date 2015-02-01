
#include "stack.h"

int main()
{

	Stack S = Create();
	if (S == NULL)
	{
		Error("Create failed\n");
		exit(1);	
	}	

	int N, M, i;
	ElementType e;

	int sta = (int) clock();		

	while (scanf("%d", &N) != EOF)
	{
		getchar();
		for(i=0; i<N; i++)
		{
			scanf("%c", &e); // you may change it depend on the ElementType
			getchar();
			Push(e, S);
		}
	
		scanf("%d", &M);
		while (M-- > 0)
			Pop(S);
	}

	int end = (int) clock();
	int ticks = end-sta;

	// Print test info
	printf("Basic\t%d\n", ticks);
 
	// MakeEmpty
	MakeEmpty(S);

	// Free stack
	free(S);
		
	return 0;
}	
