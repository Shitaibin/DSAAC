
#include "../BasicHeaderFile/list.h"

void PrintLots(List L, List P)
{
	int index = 1;
	L = L->Next;
	P = P->Next;

	while (L && P)
	{
		if (index == P->Element)
		{
			printf("%d ", L->Element);
			P = P->Next;
		}
		L = L->Next;
		index++;
	}
	puts("");
}
 
int main()
{
	List L  = Create();
	if( L == NULL)
	{
		printf("Fatal error: creating list failed!!!\n");
		exit(1);
	}

	List P = Create();
	if( P == NULL)
	{
		printf("Fatal error: creating list failed!!!\n");
		exit(1);
	}
	
	// Make sure ElementType is int
	ElementType e;
	while (scanf("%d", &e) != EOF)
	{
		// -1 is the end of L input	
		if (e == -1)
			break;
		InsertAtHead(e, L);
	}	

	
	while (scanf("%d", &e) != EOF)
	{
		InsertAtHead(e, P);
	}	

	PrintLots(L, P);

	return 0;
}
