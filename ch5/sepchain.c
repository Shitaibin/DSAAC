#include "sepchain.h"
#include <stdio.h>
#include <stdlib.h>

HashTable InitializeHashTbl(int hashtblsize) {
  HashTable H;
  H = (HashTable) malloc(sizeof(struct HashTbl));
  if (!H) {
    puts("Allocate HashTable failed");
    return NULL;
  }

  H->tablesize = hashtblsize;
  H->lists = (List *) malloc(sizeof(List) * H->tablesize);

  if (H->lists == NULL) {
    puts("Allocate seperate chain failed");
    free (H);
    return NULL;
  }

  int i;
  for (i = 0; i < H->tablesize; ++i) {
    H->lists[i] = (List) malloc(sizeof(struct ListNode));
    if (H->lists[i] == NULL)  {
      puts("Out of space");
      break;
    }
    H->lists[i]->next = NULL;
  }

  return H;
}

void DestoryHashTbl(HashTable hashtbl) {
  if (hashtbl == NULL) return;

  int i;
  for (i=0; i<hashtbl->tablesize; ++i) {
    List p = hashtbl->lists[i];
    while (p) {
      Position q = p->next;
      free(p);
      p = q;
    }
  }
  free(hashtbl->lists);
  free(hashtbl);
}

static int Hash(HashTable hashtbl, ElementType elem) {
  return elem % hashtbl->tablesize;
}

void InsertHashTbl(HashTable hashtbl, ElementType elem) {
  int index = Hash(hashtbl, elem);
 
  List list = hashtbl->lists[index];
  while (list) {
    if (list->elem == elem) return; // already exist
    list = list->next;
  } 
  
  Position p = malloc(sizeof(struct ListNode));
  if (!p) {
    puts("Insert failed, out of space");
    return ;
  }
  p->elem = elem;
  p->next = hashtbl->lists[index]->next;
  hashtbl->lists[index]->next = p;
}

Position Find(HashTable hashtbl, ElementType elem) {
  int index = Hash(hashtbl, elem);
  List list = hashtbl->lists[index];
  while (list) {
    if (list->elem == elem) return list; 
    list = list->next;
  } 

  return NULL;
}

