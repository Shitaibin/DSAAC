
/* This double stack routine without much more practical value. So, I plan to only implement Push and Pop */

#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node* Stack;

struct Node 
{
	int Top1;
	int Top2;
	int *Array;
	int Capacity;
};

int IsFull(Stack S)
{
	return S->Top1+1 == S->Top2;
}

void FatalError(const char *str)
{
	puts(str);
}

Stack CreateStack(int MaxElements)
{
	Stack S = malloc(sizeof(struct Node));
	if (S == NULL)
	{
		FatalError("Out of space");
		return NULL;
	}

	S->Array = malloc(sizeof(int) * MaxElements);
	if (S->Array == NULL)	
	{
		FatalError("Out of space");
		return NULL;
	}

	S->Capacity = MaxElements;	
	S->Top1 = -1;
	S->Top2 = S->Capacity;
	return S;
}


void Push1(int X, Stack S)
{
	if(!IsFull(S))
		S->Array[++S->Top1] = X;
}

void Pop1(Stack S)
{
	if(S->Top1 >= 0)
		--S->Top1;
}

int Top1(Stack S)
{
	if(S->Top1 >= 0)
		return S->Array[S->Top1];	
}

void Push2(int X, Stack S)
{
	if (!IsFull(S))
		S->Array[--S->Top2] = X;
}

void Pop2(Stack S)
{
	if(S->Top2<S->Capacity)
		++S->Top2;
}


int Top2(Stack S)
{
	if(S->Top2<S->Capacity)
		return S->Array[S->Top2];	
}


int main()
{
	Stack S = CreateStack(10);	// just for test
	Push1(3, S);
	Push2(2, S);
	Push1(5, S);
	Push2(4, S);
	int x = Top1(S);
	printf("top1: %d\n", x);

	x = Top2(S);
	printf("top2: %d\n", x);

	Pop1(S);
	Pop2(S);

	x = Top1(S);
	printf("top1: %d\n", x);

	x = Top2(S);
	printf("top2: %d\n", x);

	return 0;
}





