
#ifndef STACK_H_
#define STACK_H_

#define ElementType char

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

#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord 
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

#endif // STACK_H_

