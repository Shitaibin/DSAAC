#include "stack.h"

void Build(ElementType * A, int N, Stack S)
{
	int i;
	for (i=0; i<N; i++)
		Push(A[i], S);
}


int main()
{
	ElementType A[] = {'A', 'B', 'C', 'D'};

	Stack S = Create();
	Build(A, 4, S);

	printf("Top: %c\n", Top(S));
	Pop(S);

	printf("Top: %c\n", Top(S));
	Pop(S);	

	printf("Top: %c\n", Top(S));
	Pop(S);	
	
	printf("Top: %c\n", Top(S));
	Pop(S);

	printf("Empty ?  %d\n", IsEmpty(S));

	return 0;
}	
