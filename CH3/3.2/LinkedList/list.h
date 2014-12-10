#ifndef _LIST_H

#include <stdio.h>
#include <stdlib.h>

#define ElementType int


struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

Position NewNode(ElementType X);

List Create();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void InsertAtHead(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position p);
void Print(List L);
	
void FatalError(const char * Str);

/* if put this into list.c, compile test file will be wrong */
/* compile error is `invalid application of ‘sizeof’ to
/* incomplete type 'struct Node' */

struct Node
{
	ElementType Element;
	Position Next;
};

#endif
