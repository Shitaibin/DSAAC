
#include "stack.h"

void Build(ElementType * A, int N, Stack S)
{
	int i;
	for (i=0; i<N; i++)
		Push(A[i], S);
}


int main()
{

	int N;
	scanf("%d", &N);
	getchar();

	Stack S = Create();
	if (S == NULL)
	{
		Error("Create failed\n");
		exit(1);	
	}	

	int sta = (int) clock();		
	ElementType e;
	int i;
	for(i=0; i<N; i++)
	{
		scanf("%c", &e); // you may change it depend on the ElementType
		getchar();
		Push(e, S);
	}

	printf("Top: %c\n", Top(S));

	int M;
	scanf("%d", &M);
	while (M-- > 0)
		Pop(S);

	int end = (int) clock();
	printf("Size: %d\n", N);
	printf("Running time: %d ticks\n", end-sta);	
	printf("Is empty? %d\n", IsEmpty(S));
	printf("Top: %c\n", Top(S));

	// MakeEmpty
	MakeEmpty(S);
	printf("Is empty? %d\n", IsEmpty(S));
		
	return 0;
}	
