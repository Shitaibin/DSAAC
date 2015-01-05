#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avltree.h"


// if find it, return the pointer
// else, return the parent
Position FindX(int val, AvlTree tree) {
	AvlTree t = tree;
	AvlTree p = NULL;
	while (t) {
		if (val == t->elem)
			return t;
		else if (val < t->elem) {
			p = t;
			t = t->left;
		} else {
			p = t;
			t = t->right;
		}
	}
	return p;	
}

int GetNum(int n, AvlTree *t)
{
	AvlTree lefttree = *t;
	int val = rand() % n;
	Position p = FindX(val, lefttree);
	val = p->elem;
	lefttree = Delete(val, lefttree);	
	*t = lefttree;
	return val;
}


int main()
{
	srand((int)time(0));
	int n;
	scanf("%d", &n);
	int N = n;
	
	AvlTree lefttree = NULL;
	int i;
	for (i=1; i<=n; i++)
		lefttree = Insert(i, lefttree);

	AvlTree tree = NULL;
	while(n-->0) 
		tree = Insert(GetNum(N, &lefttree), tree);

	exit(EXIT_SUCCESS);
}

