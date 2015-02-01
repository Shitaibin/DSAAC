#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
void FatalError(const char *str);

/* defination */
struct Node
{
	ElementType Element;
	PtrToNode Next;
};


/* functions */
Position NewNode(ElementType X)
{
    Position P = malloc(sizeof(struct Node));
    if (P == NULL)
        FatalError("Out of Space");
    else
        P->Element = X;

    return P;
}

List Create()
{
    List L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of space.\n");
    else
	    L->Next = NULL;

    return L;
}

Position InsertToEnd(ElementType X, Position Tail)
{
    Position P = malloc(sizeof(struct Node));
    if (P == NULL)
        FatalError("Out of space!!!");  
    
    P->Element = X;
    P->Next = NULL;
    Tail->Next = P;
		return P;
}

void FatalError(const char * Str)
{
    printf("Fatal error: %s\n", Str);
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
	int M, N;
	scanf("%d%d", &M, &N);
	if (N <= 1)
		return 1;

	List L = Create();
	int e;
	int Num = N;
	Position Tail = L;
	while (Num--)
	{
		scanf("%d", &e);	
		Tail = InsertToEnd(e, Tail);
	}

//	PrintList(L);

	Position Begin = L->Next;
	Tail->Next = Begin;
	
	Num = N;
	int MM = M;
	Position Pre = Tail;
	Position P = Begin, Q;
	
	int sta = (int)clock();

	while (Num > 1)
	{
		if(MM == 0)
		{
			Q = P->Next;
			Pre->Next = Q;
//			printf("Free: %d\n", P->Element);
			free(P);
			P = Q;
			MM = M;
			Num--;
		}	
		else
		{
			MM--;
			Pre = P;
			P = P->Next;
		}
	}

	int end = (int)clock();

	if (Pre != P)
		puts("Something Wrong");
	else
		printf("Last one: %d\n", P->Element);

	free(L);
	free(P);

	printf("ticks: %d\n", end-sta);
}

	
