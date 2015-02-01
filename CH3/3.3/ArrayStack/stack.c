#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/* Implementation of functions */


/* Empty? */
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

/* Is full ? */
int IsFull(Stack S)
{
	return S->Capacity == S->TopOfStack+1;
}

/* Create an empty stack */
Stack Create(int MaxElements)
{
	if (MaxElements < MinStackSize)
		puts ("Stack is too small!!!");	// just remind, not exit	
	Stack S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
	{
		puts("Out of space!!!");
		return NULL;
	}

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL)
	{
		puts("Out of space!!!");
		return NULL;
	}
	
	S->Capacity = MaxElements;		
	MakeEmpty(S);

	return S;
}

/* Dispose stack */
void Dispose(Stack S)
{
	if ( S )
	{
		free(S->Array);
		free(S);
	}
}

/* Clear Stack */
void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

/* Push X onto S */
void Push(ElementType X, Stack S)
{
	if ( IsFull(S))
		puts("stack is full");
	else
		S->Array[++S->TopOfStack] = X;	
}

/* Pop a node from S */
void Pop(Stack S)
{
	if ( IsEmpty(S) )
		puts("stack is empty");
	else
		S->TopOfStack--;	
}

/* Get the top node */
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack]; 

	puts("stack is empty");
	return -1;
}

/* get top element and then pop it */
ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];

	puts("stack is empty");
	return -1;
}	

