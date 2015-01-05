
#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (!T)
		return NULL;
	
	T->left = MakeEmpty(T->left);
	T->right = MakeEmpty(T->right);
	free(T);
	return NULL;
}

Position Find(ElementType elem, AvlTree T)
{
	if (!T)
		return NULL;	

	if (elem < T->elem)
	{
		Find(elem, T->left);
	} else if (elem > T->elem) {
		Find(elem, T->right);
	} else {
		return T;
	}
}
	
Position FindMin(AvlTree T)
{
	if (!T)
		return NULL;

	while (T->left)
		T = T->left;
	return T;
}

Position FindMax(AvlTree T)
{
	if (!T)
		return NULL;

	while(T->right)
		T = T->right;
	return T;
}

AvlTree Insert(ElementType elem, AvlTree T) {
	if (!T)
	{
		T = (AvlTree) malloc(sizeof(struct AvlNode));
		if (!T)
			perror("malloc space for a new node");
		else {
			T->left = T->right = NULL;
			T->elem = elem;
			T->height = 0;
		}
	} else if (elem < T->elem) {
		T->left = Insert(elem, T->left);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (elem < T->left->elem) 
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	} else if (elem > T->elem) {
		T->right = Insert(elem, T->right);
		if(Height(T->right) - Height(T->left) == 2)
		{
			if (elem > T->right->elem)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	} // else: already exist, do nothing

	// update height
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return T;
}

AvlTree Delete(ElementType elem, AvlTree T) {
	if (!T)
		return NULL;

	if (elem < T->elem) {
		T->left = Delete(elem, T->left);
		if (Height(T->right) - Height(T->left) == 2) {
			if (Height(T->right->right) >= Height(T->right->left))
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
		T->height = Max(Height(T->left), Height(T->right)) + 1;
	} else if (elem > T->elem) {
		T->right = Delete(elem, T->right);
		if (Height(T->left) - Height(T->right) == 2) {
			if (Height(T->left->left) >= Height(T->left->right))
				T = SingleRotateWithLeft(T);
			else 
				T = DoubleRotateWithLeft(T);
		}
		T->height = Max(Height(T->left), Height(T->right)) + 1;
	} else {
		// delete
		if (T->left == NULL) {
			AvlTree t = T;
			T = T->right;
			free(t);
		} else if (T->right == NULL) {
			AvlTree t = T;
			T = T->left;
			free(t);
		} else {
			AvlTree t = FindMin(T->right);
			ElementType telem = t->elem;
			T->elem = t->elem;
			T->right = Delete(telem, T->right);
			if (Height(T->left) - Height(T->right) == 2) {
				if (Height(T->left->left) > Height(T->left->right))
					T = SingleRotateWithLeft(T);
				else 
					T = DoubleRotateWithRight(T);
			}
			T->height = Max(Height(T->left), Height(T->right)) + 1;
		}
	}
	return T;
}

static int Max(const int numa, const int numb)
{
	return numa > numb ? numa : numb;
}

static AvlTree SingleRotateWithLeft(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree newtree = oldtree->left;
	oldtree->left = newtree->right;
	newtree->right = oldtree;

	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(Height(newtree->left), oldtree->height) + 1;
	return newtree;
}

static AvlTree SingleRotateWithRight(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree newtree = oldtree->right;
	oldtree->right = newtree->left;
	newtree->left = oldtree;

	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtree->height, Height(newtree->right)) + 1;
	return newtree;
}

static AvlTree DoubleRotateWithLeft(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree oldtreeleft = oldtree->left;
	AvlTree newtree = oldtreeleft->right;
	oldtreeleft->right = newtree->left;
	newtree->left = oldtreeleft;
	oldtree->left = newtree->right;
	newtree->right = oldtree;
	
	oldtreeleft->height = Max(Height(oldtreeleft->left),
														Height(oldtreeleft->right)) + 1;
	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtreeleft->height, oldtree->height) + 1;
	return newtree;
}

static AvlTree DoubleRotateWithRight(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree oldtreeright = oldtree->right;
	AvlTree newtree = oldtreeright->left;
	oldtreeright->left = newtree->right;
	newtree->right = oldtreeright;
	oldtree->right = newtree->left;
	newtree->left = oldtree;

	oldtreeright->height = Max(Height(oldtreeright->left),
													Height(oldtreeright->right)) + 1;
	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtree->height, oldtreeright->height) + 1;
	return newtree;
}






