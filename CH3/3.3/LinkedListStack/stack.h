#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_H

#define ElementType char

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

void FatalError(char * Str);
void Error(char *Str);

/* Stack implementation is a linked list with a header */
struct Node
{
	ElementType Element;
	PtrToNode Next;
};


