#include <stdio.h>
#include <stdlib.h>
#include "sepchain.h"

#define SIZE 32

void PrintList(List list) {
  while (list) {
    printf("%d ", list->elem);
    list = list->next;
  }
  puts("");
}

void PrintHashTbl(HashTable hashtbl) {
  int i;
  printf("table size: %d\n", SIZE);
  for (i=0; i<hashtbl->tablesize; ++i) {
    List list = hashtbl->lists[i]->next;
    if (list) {
      printf("%d: ", i);
      PrintList(list);
    }
  }
}


int main() 
{
  int size = SIZE;
  HashTable hashtbl = InitializeHashTbl(size);
  InsertHashTbl(hashtbl, 1);
  InsertHashTbl(hashtbl, 2);
  InsertHashTbl(hashtbl, 3);
  InsertHashTbl(hashtbl, 4);
  InsertHashTbl(hashtbl, 5);
  InsertHashTbl(hashtbl, 44);
  InsertHashTbl(hashtbl, 36);
  InsertHashTbl(hashtbl, 33);

  PrintHashTbl(hashtbl);

  return 0;
}
