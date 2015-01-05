#include "stack.h"


/* Implementation of functions */

/* Create a new node and initialize with value X */

PtrToNode NewNode(ElementType X)
{	
	PtrToNode P = malloc(sizeof(struct Node));
	if ( !P )
		FatalError("Out of Space!!\n");
	else
		P->Element = X;

	return P;
}

/* Empty? */

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

/* Create an empty stack */

Stack Create()
{
	Stack S = NewNode(0); 
	// S->Next = NULL;
	MakeEmpty(S); // Do you know why here using `MakeEmpty(S)` not `S->next = NULL` ?
	return S;
}

/* Clear Stack */

void MakeEmpty(Stack S)
{
	if (S == NULL)
		Error("Must use Create first");
	else
		while (!IsEmpty(S))
			Pop(S);
}

/* Push X onto S */

void Push(ElementType X, Stack S)
{
	PtrToNode P = NewNode(X);
	if ( P )
	{
		P->Next = S->Next;
		S->Next = P;
	}
}

/* Pop a node from S */

void Pop(Stack S)
{
	if (!IsEmpty(S))
	{
		PtrToNode P = S->Next;
		S->Next = P->Next;
		free(P);
	}
	else 
		Error("Empty Stack");

}

/* Get the top node */

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;

	Error("Empty Stack");
	return 0;
}

