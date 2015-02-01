
#ifndef _STACK_H

#include "basic.h"

#define BUFSIZE 1000

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

void InitializingBuf(); 
void DisposeBuf();
void EmptyBuf();

PtrToNode AllocNode();
void FreeNode(PtrToNode P);

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


/* Management implementation */
struct Buf 
{
	Stack stack; // management stack
	int Size;	// the max size of the management stack
	int N;		// the size of the management stack 
}; 

struct Buf* StackBuf;	// Create it when create a stack


  
