
#include "../BasicHeaderFile/list.h"

List Reverse(List L)
{
  Position Left = L->Next;
  L->Next = NULL;
  while (Left)
  {
    InsertAtHead(Left->Element, L);
    Left = Left->Next;
  }

  return L;
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
  L = Reverse(L);
  PrintList(L);

  return 0;
}
