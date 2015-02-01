#include "../BasicHeaderFile/list.h"

Position FindSelfAdjusting(ElementType X, List L)
{
  Position Pre = L;
  Position P = Pre->Next;
  while(P)
  {
    if (P->Element == X)
    {
      Pre->Next = P->Next;
      P->Next = L->Next;
      L->Next = P;
      break;
    }

    Pre = P;
    P = P->Next;
  }

  return P;
}

void PrintList(List L)
{
  L = L->Next;
  while (L)
  {
    printf("%d ", L->Element);
    L = L->Next;
  }
  puts("");
}

int main()
{
  List L = Create();
  ElementType e;

  e = 3;
  InsertAtHead(e, L);
  e = 2;
  InsertAtHead(e, L);
  e = 1;
  InsertAtHead(e, L);

  PrintList(L);
  FindSelfAdjusting(3, L);
  PrintList(L);

  return 0;
}
