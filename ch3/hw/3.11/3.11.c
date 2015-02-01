
#include "../BasicHeaderFile/list.h"

Position FindRec(ElementType X, List L)
{
	if(L->Element == X)
		return L;
	else
		FindRec(X, L->Next);
}

int main()
{
	List L = Create();
	int N;
	scanf("%d", &N);
	int FindNum = 1;
	ElementType e;
	while (N--)
	{
		scanf("%d", &e);
		InsertAtHead(e, L);
	}

	Position Q;
	int sta1 = clock();
	Q = Find(FindNum, L);
	int end1 = clock();
	printf("sta1: %d\tend1: %d\n", sta1, end1);;

	Position P;
	int sta = clock();
	P = FindRec(FindNum, L->Next);
	int end = clock();
	
	printf("sta: %d\tend: %d\n", sta, end);;
	printf("FindNum: %d\titer: %d\trecu: %d\n", FindNum, Q->Element, P->Element);
	printf("iter: %d\nrecu: %d\n", end1-sta1, end-sta);

	return 0;
}	



