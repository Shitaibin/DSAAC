#include "list.h"


void Build (const int *A, const int N, List L)
{
	int i;
	for (i=N-1; i>=0; i--)
		InsertAtHead(A[i], L);
}

int main()
{

	List L = Create(); 
	if (L == NULL)
	{
		FatalError("Create list failed.\n");
		exit(1);
	}

	int A[5] = {1, 2, 3, 4, 5};	

	Build(A, 5, L);
	puts("List:");
	Print(L);

	printf("Is empty? \t %d\n", IsEmpty(L));
	MakeEmpty(L);
	Print(L);
	
	Build(A, 5, L);
	Position ipos = Find(3, L);
	Insert(6, L, ipos);
	Print(L);

	puts("Delete 1");
	Delete(1, L);
	Print(L);
		
	puts("Delete list");
	DeleteList(L);
	Print(L);
	return 0;
}

