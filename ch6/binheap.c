#include <stdio.h>
#include <stdlib.h>
#include "binheap.h"

PriorityQueue InitializePriorityQueue(int maxelements) {
  PriorityQueue prique = (PriorityQueue) malloc (sizeof(struct HeapStruct));
  if (prique == NULL) {
    puts("Out of space");
    return NULL;
  }

  prique->capacity = maxelements;
  prique->size = 0;

  prique->elements = (ElementType *) 
                      malloc (sizeof(ElementType) * (maxelements + 1));
  if (prique->elements == NULL) {
    puts("Out of space");
    free(prique);
    return NULL;
  }

//  H->elements[0] = MinData;
  return prique;
}

void InsertPriorityQueue(PriorityQueue prique, ElementType elem) {
  if (IsFull(prique)) {
    puts("Priority queue is full");
    return;
  }

  int i;
  for (i = ++prique->size; prique->elements[i/2] > elem; i /= 2) 
    prique->elements[i] = prique->elements[i/2];
    
  prique->elements[i] = elem;
}

void DestoryPriorityQueue(PriorityQueue prique) {
   if (prique->elements) 
     free(prique->elements);
   free(prique);
}

void MakeEmptyPriorityQueue(PriorityQueue prique) {
  prique->size = 0;
}

ElementType DeleteMin(PriorityQueue prique) {
//  assert(prique->size > 0); 
  ElementType minelem = prique->elements[1];
  ElementType lastelem = prique->elements[prique->size--];

  int i = 1, child;
  for (i = 1; i * 2 < prique->size; i = child) {
    child = i * 2;
    if (child != prique->size && 
        prique->elements[child+1] < prique->elements[child])
      ++child;
    prique->elements[i] = prique->elements[child];
  }

  prique->elements[i] = lastelem;
  return minelem;
}

ElementType GetMin(PriorityQueue prique) {
  return prique->elements[1];
}

int IsEmptyPriorityQueue(PriorityQueue prique) {
  return prique->size == 0;
}

int IsFullPriorityQueue(PriorityQueue prique) {
  return prique->size == prique->capacity;
}

