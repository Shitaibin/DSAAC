
#ifndef _STACK_H

#include "basic.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

PtrToNode NewNode(ElementType X);

int IsEmpty(Stack S);
Stack Create();
void Dispose(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif

/* Stack implementation is a linked list with a header */
struct Node
{
	ElementType Element;
	PtrToNode Next;
};


