struct Node;
struct NodeRecord;
typedef struct Node* PtrToNode;
typedef PtrToNode Postion;
typedep PtrToNode List;
typedef struct NodeRecord* ListRecord;

struct Node
{
  ElementType Element;
  int flag;
  Position Next;
};

struct NodeRecord
{
  List L;       /* linked list */
  int Size;     /* the number of current nodes */
  int DelSize;  /* the number of current deleted nodes */ 
};

void FakeDelete(Position P, ListRecord LR)
{
  P->Flag = 0;
  if (LR->DelSize > LR->Size/2)
  {
    RealDelete(LR);
  }
}

void ReadDelete(ListRecord LR)
{
  Position Pre = LR->List;
  Position P = Pre->Next;
  while(P)
  {
    if(P->Flag == 0)
    {
      Pre->Next = P->Next;
      free(P);
      P = Pre->Next;
    }
  }
}
