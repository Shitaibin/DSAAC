#include "optstack.h"


/* Implementation of functions */

/* Initializing Buf */

void InitializingBuf()
{
	StackBuf = malloc(sizeof(struct Buf));
	if (StackBuf == NULL)
	{
		FatalError("Create management buffer failed");
		exit(2);
	}
	
	StackBuf->stack = malloc(sizeof(struct Node)); // create management stack
	if (StackBuf->stack == NULL)
	{
		FatalError("Create management stack failed");
		exit(3);
	}
//	MakeEmpty(StackBuf->stack); //it can't use it, because MakeEmpty will call Pop, then call FreeNode
	
	/* for test we just use Next is NULL */
//	StackBuf->Next = NULL;
	EmptyBuf();
	
	StackBuf->Size = BUFSIZE;
	StackBuf->N = 0;
	
}

/* Dispose Buf */

void DisposeBuf()
{
	if (StackBuf->stack->Next)
	{
		EmptyBuf();
	}

	free(StackBuf->stack);
	free(StackBuf);
}

/* Exectly pop nodes in management stack */

void EmptyBuf()
{
	PtrToNode P = StackBuf->stack->Next;
	StackBuf->stack->Next = NULL;
	while ( P )
	{
		PtrToNode Q = P->Next;
		free(P);
		P = Q;
	}
}

/* Alloc space for a new node */
PtrToNode AllocNode()
{
	PtrToNode P; 
	if (StackBuf->N > 0)
	{
		P = StackBuf->stack->Next;
		StackBuf->stack->Next = P->Next;
		StackBuf->N --;
	}
	else
	{
		P = malloc(sizeof(struct Node));
	}			
	
	return P;		
}

/* Free a Node */
void FreeNode(PtrToNode P)
{
	if (StackBuf->N < StackBuf->Size)
	{
		P->Next = StackBuf->stack->Next;
		StackBuf->stack->Next = P;
		StackBuf->N ++;
	}
	else 
	{
		free(P);
	}	
	
}

/* Create a new node and initialize with value X */

PtrToNode NewNode(ElementType X)
{	
	PtrToNode P = AllocNode();
		
	if ( !P )
		FatalError("Out of Space!!\n");
	else 
		P->Element = X;

	return ;
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
		FreeNode(P);
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

