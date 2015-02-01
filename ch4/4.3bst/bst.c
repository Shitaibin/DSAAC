
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


BSTree MakeEmpty(BSTree tr)
{
	if (tr == NULL)
		return tr;
	
	MakeEmpty(tr->left);
	MakeEmpty(tr->right);
	free(tr);
	return NULL;
}

Position Find(ElementType x, BSTree tr)
{
	if(tr == NULL)
		return tr;

	if(x > tr->elem)
		return Find(x, tr->right);
	else if(x < tr->elem)
		return Find(x, tr->left);
	else
		return tr;
}

Position FindMin(BSTree tr)
{
	if (tr == NULL)
		return NULL;

	while (tr->left)
		tr = tr->left;
	
	return tr;
}

Position FindMax(BSTree tr)
{
	if(tr == NULL)
		return NULL;
	
	while(tr->right)
		tr = tr->right;

	return tr;
}

BSTree Insert(ElementType x, BSTree tr)
{
	if (tr == NULL)
	{
		// node not exist, new subtree
		tr = (BSTree) malloc(sizeof(struct BSTNode));
		if (tr == NULL)
			FatalError("Out of space!!!");
		else
		{
			tr->elem = x;
			tr->left = tr->right = NULL;
		}
	}
	else
	{
		if(x < tr->elem)
			tr->left = Insert(x, tr->left);
		else if(x > tr->elem)
			tr->right = Insert(x, tr->right);
		// else: already exist, do nothing
	}

	return tr;
}

BSTree Delete(ElementType x, BSTree tr)
{
	if(tr == NULL)
		return NULL;

	if(x < tr->elem)
		tr->left = Delete(x, tr->left);
	else if(x > tr->elem)
		tr->right = Delete(x, tr->right);
	else
	{
		if(tr->left && tr->right)
		{
//			Position p = FindMin(tr->right);
//			tr->elem = p->elem;
//			tr->right = Delete(p->elem, tr->right);
			tr->elem = DeleteMin(tr->right); // this operation also can be down by the above 3 sentences;
		}
		else
		{
			Position temp = tr;
			if(tr->left == NULL)
				tr = tr->right;
			else if(tr->right == NULL)
				tr = tr->left;
			free(temp);
		}
	}

	return tr;
}

ElementType Retrieve(Position p)
{
	return p->elem;
}

ElementType DeleteMin(BSTree tr)
{
	if(tr == NULL)
		return -1;

	ElementType temp;
	if(tr->left == NULL)
	{
		temp = tr->elem;
		free(tr);
		return temp;
	}

	while(tr->left->left)
		tr = tr->left;
	temp = tr->left->elem;
	free(tr->left);
	tr->left = NULL;

	return temp;
}	

void FatalError(const char* str)
{
	puts(str);
}



