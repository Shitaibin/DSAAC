#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

int CountNodes(AvlTree tree) {
	static int numnodes = 0;
	if (!tree)
		return numnodes;

	if (tree)
		numnodes++;
	if (tree->left)
		CountNodes(tree->left);
	if (tree->right)
		CountNodes(tree->right);	
	return numnodes;
}

int CountLeaves(AvlTree tree) {
	static int numleaves = 0;

	if (!tree)
		return numleaves;

	if (tree->left == NULL && tree->right == NULL) 
		numleaves++;
	else {
		if (tree->left)
			CountLeaves(tree->left);
		if (tree->right)
			CountLeaves(tree->right);
	}
	return numleaves;
}

int CountFullNodes(AvlTree tree) {
	static int numfullnodes = 0;
	if (!tree)
		return numfullnodes;

	if (tree->left && tree->right) 
		numfullnodes++;
	if (tree->left)
		CountFullNodes(tree->left);
	if (tree->right)
		CountFullNodes(tree->right);
	return numfullnodes;
}
	 
int main()
{
	AvlTree tree = NULL;
	tree = Insert(1, tree);
	tree = Insert(2, tree);
	tree = Insert(3, tree);
	tree = Insert(4, tree);
	tree = Insert(5, tree);
	tree = Insert(6, tree);
	tree = Insert(7, tree);

	printf("a. number of nodes in T: %d\n", CountNodes(tree));
	printf("b. number of leaves in T: %d\n", CountLeaves(tree));
	printf("c. number of full nodes in T: %d\n", CountFullNodes(tree));

	exit(EXIT_SUCCESS);
}
