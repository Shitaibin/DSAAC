#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void PreOrder(BSTree T)
{
	if(T == NULL)
		return ;
	printf("%d ", T->elem);
	if(T->left)
		PreOrder(T->left);
	if(T->right)
		PreOrder(T->right);
}

int main()
{
	BSTree T = NULL; // without initialize 
	T = Insert(8, T);
	T = Insert(4, T);
	T = Insert(10, T);
	T = Insert(2, T);
	T = Insert(7, T);
	T = Insert(9, T);
	T = Insert(11, T);
	T = Insert(1, T);
	T = Insert(3, T);
	T = Insert(6, T);

	PreOrder(T);
	puts("");

	T = Delete(4, T);
	PreOrder(T);
	puts("");

	return 0;
}

