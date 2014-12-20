/* I will not test this function, cause now I didn't implemente doubled linked list. */ 

void SwapWithPointer(PtrToNode P)
{
  PtrToNonde Pre = P->Pre;
	PtrToNode Q = P->Next;
  PtrToNode Left = Q->Next;

  Pre->Next = Q;
  Q->Next = P;
  P->Next = Left;
	
	Q->Pre = Pre;
	P->Pre = Q;
	Left->Pre = P;
}
