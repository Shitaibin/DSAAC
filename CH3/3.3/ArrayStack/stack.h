
#ifndef _STACK_H

#include "basic.h"

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack Create(int MaxElements);
void Dispose(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif


/* Stack implementation is a linked list with a header */

#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord 
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};


