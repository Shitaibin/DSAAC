#include "list.h"





/* implementation of functions */

/* Create a new node with value X */

Position NewNode(ElementType X)
{
	Position P = malloc(sizeof(struct Node));
	if (P == NULL)
		FatalError("Out of Space");
	else
		P->Element = X;

	return P;
}

/* Create an empty List with a header node */

List Create()
{
	List L = malloc(sizeof(struct Node));
	if (L == NULL)
		FatalError("Out of space.\n");
	else
		L->Next = NULL;

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
	return L->Next == NULL;
}

/* Retrun true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

/* Retrun Position of X in L, NULL if not found */

Position Find(ElementType X, List L)
{
	Position p = L->Next;
	while (p && p->Element != X)
		p = p->Next;

	return p;
}

/* Delete first occurence of X from a list L */
/* Assume use of a header node */

void Delete(ElementType X, List L)
{
	Position pre = FindPrevious(X, L);
	if (pre)
	{
		Position t = pre->Next;
		pre->Next = t->Next;
		free(t);
	}
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes use of a header node */

Position FindPrevious(ElementType X, List L)
{
	Position pre = L;
	while(pre->Next && pre->Next->Element != X)
		pre = pre->Next;

	if (pre->Next)
		return pre;
	else	
		return NULL;
}

/* Insert (after legal position p) */
/* Header implemetation assumend */
/* Parameter L is unused in this implemetation */

void Insert(ElementType X, List L, Position P)
{
	Position p = malloc(sizeof(struct Node));
	if (p == NULL)
		FatalError("Out of space!!!");	
	
	p->Element = X;
	p->Next = P->Next;
	P->Next = p;
}

/* Insert a Node at the beginning */

void InsertAtHead(ElementType X, List L)
{
	Position P = NewNode(X); 
	if ( P )
	{
		P->Next = L->Next;
		L->Next = P;
	}
}	

	
/* Delete List */
/* Assumes use of a header node */
/* Do not delete the header not */

void DeleteList(List L)
{
	Position p = L->Next;
	L->Next = NULL;

	while ( p )
	{
		Position q = p->Next;
		free(p);
		p = q;
	}
}






/* Retrieve the value in at the Position P */
ElementType Retrieve(Position P)
{
	return P->Element;
}


/* Print elements in order */

void Print(List L)
{
	Position P = L->Next;
	for ( ; P ; P=P->Next )	
		printf("%d ", P->Element);	

	puts("");
}

/* Print error msg */
void FatalError(const char * Str)
{
	printf("Fatal error: %s\n", Str);
}




