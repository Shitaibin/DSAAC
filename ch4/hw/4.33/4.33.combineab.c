#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void Fillxy(BSTree tr, int parenty) {
	static int cursor = 0;
	if (!tr)
		return;

	tr->y = parenty - 1;
	if (tr->left)
		Fillxy(tr->left, tr->y);
	tr->x = cursor++;
	printf("%d\t%d\t%d\n", tr->elem, tr->x, tr->y);

	if (tr->right)
		Fillxy(tr->right, tr->y);
}

int main()
{
	BSTree tree = NULL;
	tree = Insert(4, tree);
	tree = Insert(2, tree);
	tree = Insert(6, tree);
	tree = Insert(1, tree);
	tree = Insert(3, tree);
	tree = Insert(5, tree);
	tree = Insert(7, tree);

	Fillxy(tree, 1);

	exit(EXIT_SUCCESS);
}
