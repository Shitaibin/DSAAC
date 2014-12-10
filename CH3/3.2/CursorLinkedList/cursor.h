#ifndef _CURSOR_H

#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define SPACESIZE 1000		// set space size as 1000

struct Node;
typedef int PtrToNode;   // subscript is the address now
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(); 	// initialize space
static Position CursorAlloc(); // simulate malloc
static void CursorFree(Position P); // simulate free	

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
	
#endif

void FatalError(const char * Str);

/* if put this into list.c, compile test file will be wrong */
/* compile error is `invalid application of ‘sizeof’ to
/* incomplete type 'struct Node' */

struct Node
{
	ElementType Element;
	Position Next;
};


struct Node CursorSpace[ SPACESIZE ];
