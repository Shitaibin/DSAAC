

#include "../BasicHeaderFile/list.h"

void SwapWithPointer(PtrToNode Pre, PtrToNode P)
{
	PtrToNode Q = P->Next;
	PtrToNode Left = Q->Next;

	Pre->Next = Q;
	Q->Next = P;
	P->Next = Left;
}

void PrintList(List L)
{
	L = L->Next;
	while (L)
	{
		printf("%d ", L->Element);
		L = L->Next;
	}
	puts("");
}

int main()
{
	ElementType e;
	List L = Create();
	
	e = 6;
	InsertAtHead(e, L);
	e = 5;
	InsertAtHead(e, L);
	e = 4;
	InsertAtHead(e, L);
	e = 3;
	InsertAtHead(e, L);
	e = 2;
	InsertAtHead(e, L);
	e = 1;
	InsertAtHead(e, L);
	PrintList(L);

	PtrToNode Pre = L, P;
	int N = 3;
	while (N--)
		Pre = Pre->Next;
	P = Pre->Next;

	printf("Pre->Element: %d\n", Pre->Element);
	printf("P->Element: %d\n", P->Element);
	
	SwapWithPointer(Pre, P);
	PrintList(L);

	return 0;
} 










