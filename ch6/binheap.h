#ifndef _BINHEAP_H

#define ElementType int

struct HeapStruct;
struct HeapStruct {
  int capacity;
  int size;
  ElementType *elements;
};

typedef struct HeapStruct *PriorityQueue;

PriorityQueue InitializePriorityQueue( int MaxElements);
void DestoryPriorityQueue(PriorityQueue prique);
void MakeEmptyPriorityQueue(PriorityQueue prique);
void InsertPriorityQueue(PriorityQueue prique, ElementType elem);
ElementType DeleteMin(PriorityQueue prique);
ElementType GetMin(PriorityQueue prique);
int IsEmptyPriorityQueue(PriorityQueue prique);
int IsFullPriorityQueue(PriorityQueue prique);

#endif // _BINHEAP_H

