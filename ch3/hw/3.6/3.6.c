/* No test for this function */

/* the list has a node */

/* If you want to use list.h, something should be rewrite */
typedef PolynomialNode* PtrToNode;

struct PolynomialNode{
  double Coefficient;
  int Exponent;
  PtrToNode Next;
  PtrToNode Tail;
};

int Cmp(float X, float Y)
{
  int x = (int)(X * 1000000);
  int y = (int)(Y * 1000000);
  return x-y;
}

void InserToLAtEnd(Double Coff, int Exp, List L)
{
  if(IsZero(Coff))
    return;

  PtrToNode P = NewNode(Coff, Exp); /* Need rewrite NewNode */
  if(!P) /* failed */ 
    return;

  L->Tail->Next = P;
  P->Next = NULL;
}
  
List Polynomial(List L1, List L2)
{
  List L = Create();
  
  L1 = L1->Next;
  L2 = L2->Next;

  while(L1 && L2)
  {
    int CmpResult = Cmp(L1->Coefficient, L2->Cofficient);
    if (CmpResult < 0)
    {
      InsertToLAtEnd(L1->Coefficient, L1->Exponent);
      L1 = L1->Next;
    }
    else if (CmpResult > 0)
    {
      InsertToLAtEnd(L2->Coefficient, L2->Exponent);
      L2 = L2->Next;
    }
    else
    {
      InsertToLAtEnd(L1->Coefficient+L2->Cofficient, L2->Exponent);
      L1 = L1->Next;
      L2 = L2->Next;
    }
  }

  while (L1)
  { 
    InsertToLAtEnd(L1->Coefficient, L1->Exponent);
    L1 = L1->Next;
  }

  while (L2)
  { 
    InsertToLAtEnd(L2->Coefficient, L2->Exponent);
    L2 = L2->Next;
  }
	return L;
}

