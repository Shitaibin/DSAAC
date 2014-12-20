
/* L1 and L2 are two sorted list. Computing the union of L1 and L2 */

#include "../BasicHeaderFile/list.h"

int Cmp(ElementType X, ElementType Y)
{
	return X-Y;
}

void ListIntersection(List L1, List L2)
{
	L1 = L1->Next;
	L2 = L2->Next;

	while (L1 && L2)
	{
		int CmpResult = Cmp(L1->Element, L2->Element); 
		if (CmpResult < 0)
		{
			printf("%d ", L1->Element);
			L1 = L1->Next;
		}
		else if (CmpResult > 0)
		{
			printf("%d ", L2->Element);
			L2 = L2->Next;
		}
		else
		{
			printf("%d ", L1->Element);
			L1 = L1->Next;
			L2 = L2->Next;
		}
	}
		while(L1)	
		{
			printf("%d ", L1->Element);
			L1 = L1->Next;
		}
	
		while(L2)	
		{
			printf("%d ", L2->Element);
			L2 = L2->Next;
		}
}	

int main()
{
	List L1 = Create();
	List L2 = Create();

	ElementType e;
	e = 5;
	InsertAtHead(e, L1);
	e = 3;
	InsertAtHead(e, L1);
	e = 1;
	InsertAtHead(e, L1);

	e = 4;
	InsertAtHead(e, L2);
	e = 3;
	InsertAtHead(e, L2);
	e = 2;
	InsertAtHead(e, L2);

	ListIntersection(L1, L2);

	puts("");

	return 0;
} 
