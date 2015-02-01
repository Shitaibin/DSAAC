#ifndef _HashSep_H_

#define ElementType int

struct ListNode;
struct ListNode {
  ElementType elem;
  struct ListNode *next;
};
typedef struct ListNode *Position;
typedef struct ListNode *List;

struct HashTbl;
struct HashTbl {
  int tablesize;
  List *lists;
};
typedef struct HashTbl *HashTable;

HashTable InitializeHashTbl(int hashtblsize);
void DestroyHashTbl(HashTable hashtbl);
Position Find(HashTable hashtbl, ElementType elem);
void InsertHashTbl(HashTable hashtbl, ElementType elem);
inline ElementType RetriveHashtbl(Position p) { return p->elem; }

#endif  // _HashSep_H_
