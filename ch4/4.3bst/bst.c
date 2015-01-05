
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


BSTree MakeEmpty(BSTree T)
{
	if (T == NULL)
		return T;
	
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	free(T);
	return NULL;
}

Position Find(ElementType X, BSTree T)
{
	if(T == NULL)
		return T;

	if(X > T->Element)
		return Find(X, T->Right);
	else if(X < T->Element)
		return Find(X, T->Left);
	else
		return T;
}

Position FindMin(BSTree T)
{
	if (T == NULL)
		return NULL;

	while (T->Left)
		T = T->Left;
	
	return T;
}

Position FindMax(BSTree T)
{
	if(T == NULL)
		return NULL;
	
	while(T->Right)
		T = T->Right;

	return T;
}

BSTree Insert(ElementType X, BSTree T)
{
	if (T == NULL)
	{
		// node not exist, new subtree
		T = malloc(sizeof(struct BSTNode));
		if (T == NULL)
			FatalError("Out of space!!!");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if(X < T->Element)
			T->Left = Insert(X, T->Left);
		else if(X > T->Element)
			T->Right = Insert(X, T->Right);
		// else: already exist, do nothing
	}

	return T;
}

BSTree Delete(ElementType X, BSTree T)
{
	if(T == NULL)
		return NULL;

	if(X < T->Element)
		T->Left = Delete(X, T->Left);
	else if(X > T->Element)
		T->Right = Delete(X, T->Right);
	else
	{
		if(T->Left && T->Right)
		{
//			Position P = FindMin(T->Right);
//			T->Element = P->Element;
//			T->Right = Delete(P->Element, T->Right);
			T->Element = DeleteMin(T->Right); // this operation also can be down by the above 3 sentences;
		}
		else
		{
			Position Temp = T;
			if(T->Left == NULL)
				T = T->Right;
			else if(T->Right == NULL)
				T = T->Left;
			free(Temp);
		}
	}

	return T;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

ElementType DeleteMin(BSTree T)
{
	if(T == NULL)
		return -1;

	ElementType Temp;
	if(T->Left == NULL)
	{
		Temp = T->Element;
		free(T);
		return Temp;
	}

	while(T->Left->Left)
		T = T->Left;
	Temp = T->Left->Element;
	free(T->Left);
	T->Left = NULL;

	return Temp;
}	

void FatalError(const char* str)
{
	puts(str);
}



