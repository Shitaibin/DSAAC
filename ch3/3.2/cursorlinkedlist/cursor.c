#include "cursor.h"


/* implementation of functions */

/* Initialize space */

void InitializeCursorSpace()
{
	int i;
	for (i=0; i<SPACESIZE; i++)
		CursorSpace[i].Next = i+1;
	
	CursorSpace[SPACESIZE-1].Next = 0;
}	

/* Alloc space from CursorSpace */

static CursorAlloc()
{
	Position P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

/* Free space to CursorSpace */

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

/* Create a new node with value X */

Position NewNode(ElementType X)
{
	Position P = CursorAlloc();
	if (P == 0)
		FatalError("Out of Space\n");
	else
		CursorSpace[P].Element = X;

	return P;
}

/* Create an empty List with a header node */

List Create()
{
	List L = CursorAlloc(); 
	if (L == 0)
		FatalError("Out of space.\n");
	else
		CursorSpace[L].Next = 0;

	return L;
}

/* Make a list L to empty */

List MakeEmpty(List L)
{
	DeleteList(L);
	return L;
}

/* Retrun true if L is empty */

int IsEmpty(List L)
{
	return CursorSpace[L].Next == 0;
}

/* Retrun true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

/* Retrun Position of X in L, 0 if not found */

Position Find(ElementType X, List L)
{
	Position P = CursorSpace[L].Next;
	while (P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

/* Delete first occurence of X from a list L */
/* Assume use of a header node */

void Delete(ElementType X, List L)
{
	Position pre = FindPrevious(X, L);
	if (pre)
	{
		Position t = CursorSpace[pre].Next;
		CursorSpace[pre].Next = CursorSpace[t].Next;
		CursorFree(t);
	}
}

/* If X is not found, then Next field of returned */
/* Position is 0 */
/* Assumes use of a header node */

Position FindPrevious(ElementType X, List L)
{
	Position pre = L;
	while(CursorSpace[pre].Next && CursorSpace[CursorSpace[pre].Next].Element != X)
		pre = CursorSpace[pre].Next;

	if (CursorSpace[pre].Next)
		return pre;
	else	
		return 0;
}

/* Insert (after legal position p) */
/* Header implemetation assumend */
/* Parameter L is unused in this imQlemetation */

void Insert(ElementType X, List L, Position P)
{
	Position Q = NewNode(X); 
	if (Q == 0)
		return ;
	
	CursorSpace[Q].Element = X;
	CursorSpace[Q].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = Q;
}

/* Insert a Node at the beginning */

void InsertAtHead(ElementType X, List L)
{
	Position P = NewNode(X); 
	if ( P )
	{
		CursorSpace[P].Next = CursorSpace[L].Next;
		CursorSpace[L].Next = P;
	}
}	

	
/* Delete List */
/* Assumes use of a header node */
/* Do not delete the header not */

void DeleteList(List L)
{
	Position p = CursorSpace[L].Next;
	CursorSpace[L].Next = 0;

	while ( p )
	{
		Position q = CursorSpace[p].Next;
		CursorFree(p);
		p = q;
	}
}






/* Retrieve the value in at the Position P */
ElementType Retrieve(Position P)
{
	return CursorSpace[P].Element;
}


/* Print elements in order */

void Print(List L)
{
	Position P = CursorSpace[L].Next;
	for ( ; P ; P=CursorSpace[P].Next )	
		printf("%d ", CursorSpace[P].Element);	

	puts("");
}

/* Print error msg */
void FatalError(const char * Str)
{
	printf("Fatal error: %s\n", Str);
}




