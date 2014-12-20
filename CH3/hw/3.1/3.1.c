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
