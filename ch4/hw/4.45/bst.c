#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


TBSTree MakeEmpty(TBSTree tr)
{
	if (tr == NULL)
		return tr;
	if (tr->leftthread == 0) 	
		MakeEmpty(tr->left);
	if (tr->rightthread == 0)
		MakeEmpty(tr->right);
	free(tr);
	return NULL;
}

Position Find(ElementType x, TBSTree tr)
{
	if(tr == NULL)
		return tr;

	if(x > tr->elem && tr->rightthread == 0)
		return Find(x, tr->right);
	else if(x < tr->elem && tr->leftthread == 0)
		return Find(x, tr->left);
	else
		return tr;
}

Position FindMin(TBSTree tr)
{
	if (tr == NULL)
		return NULL;

	while (tr->leftthread == 0)
		tr = tr->left;
	
	return tr;
}

Position FindMax(TBSTree tr)
{
	if(tr == NULL)
		return NULL;
	
	while (tr->rightthread == 0)
		tr = tr->right;

	return tr;
}

void InsertAtLeft(ElementType x, TBSTree tr) {
	TBSTree newnode = (TBSTree) malloc(sizeof(struct TBSTNode));
	if (newnode == NULL)
		FatalError("Out of space!!!");
	else
	{
		newnode->elem = x;
		newnode->left = tr->left;
		newnode->right = tr;
		newnode->leftthread = newnode->rightthread = 1;

		tr->left = newnode;
		tr->leftthread = 0;
	}
}

void InsertAtRight(ElementType x, TBSTree tr) {
	TBSTree newnode = (TBSTree) malloc(sizeof(struct TBSTNode));
	if (newnode == NULL)
		FatalError("Out of space!!!");
	else
	{
		newnode->elem = x;
		newnode->left = tr;
		newnode->right = tr->right;
		newnode->leftthread = newnode->rightthread = 1;

		tr->right = newnode;
		tr->rightthread = 0;
	}
}
	
TBSTree Insert(ElementType x, TBSTree tr)
{
	if (tr == NULL)
	{
		// it's an empty tree 
		tr = (TBSTree) malloc(sizeof(struct TBSTNode));
		if (tr == NULL)
			FatalError("Out of space!!!");
		else
		{
			tr->elem = x;
			tr->left = tr->right = NULL;
			tr->leftthread = tr->rightthread = 0;
		}
	}
	else
	{
		if(x < tr->elem) {
			if (tr->leftthread == 0 && tr->left)
				tr->left = Insert(x, tr->left);
			else {
				InsertAtLeft(x, tr);
			}
		}	else if(x > tr->elem) {
			if (tr->rightthread == 0 && tr->right)
				tr->right = Insert(x, tr->right);
			else {
				InsertAtRight(x, tr);
			}
		}
		// else: already exist, do nothing
	}
	return tr;
}

TBSTree DeleteNodeNoRightChild(Position parent, TBSTree tr) {
	TBSTree subtree = tr->left;
	if (parent->left == tr) {
		parent->left = tr->left;
		parent->leftthread = tr->leftthread;
		if (subtree && subtree->rightthread)
			subtree->right = parent;	// subtree's father will be delete
	} else {
		parent->right = tr->left;
		parent->rightthread = tr->leftthread;
		if (subtree && subtree->leftthread) 
			subtree->left = parent;	// subtree's father will be delete
	}
	free(tr);
	return subtree;
}

TBSTree DeleteNodeNoLeftChild(Position parent, TBSTree tr) {
	TBSTree subtree = tr->right;
	if (parent->left == tr) {
		parent->left = tr->right;
		parent->leftthread = tr->rightthread;
		if (subtree && subtree->rightthread)
			subtree->right = parent;	// subtree's father will be delete
	} else {
		parent->right = tr->right;
		parent->rightthread = tr->rightthread;
		if (subtree && subtree->leftthread) 
			subtree->left = parent;	// subtree's father will be delete
	}
	free(tr);
	return subtree;
}

TBSTree Delete(ElementType x, Position parent, TBSTree tr)
{
	if(tr == NULL)
		return NULL;

	if(x < tr->elem)
		tr->left = Delete(x, tr, tr->left);
	else if(x > tr->elem)
		tr->right = Delete(x, tr, tr->right);
	else {
		// find the node
		if(tr->leftthread == 0 && tr->rightthread == 0)
		{
			if (tr->left && tr->right) {
				// has two child
				Position p = FindMin(tr->right);
				tr->elem = p->elem;
				tr->right = Delete(p->elem, tr, tr->right);
			} else { 
				// the tree has only the root node
				free(tr);
				return NULL;
			}
		} else if (tr->rightthread == 1) {
			// no right child
			tr = DeleteNodeNoRightChild(parent, tr);
		} else {
			// has right child 
			tr = DeleteNodeNoLeftChild(parent, tr);
		}
	}
	return tr;
}

ElementType Retrieve(Position p)
{
	return p->elem;
}

void FatalError(const char* str)
{
	puts(str);
}



