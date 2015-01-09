#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/**
 * This function is not right
 */
void InOrder(TBSTree tr) {
	if (!tr) 
		return;

	if (tr->leftthread == 0)
		InOrder(tr->left);
	printf("%p\t%d\n", tr, tr->elem);
	if (tr->rightthread == 0)
		InOrder(tr->right);
}

void InOrderTraversal(TBSTree tr) {
	InOrder(tr);
	puts("");
}

int main()
{
	TBSTree tree = NULL;
	tree = Insert(4, tree);
	tree = Insert(2, tree);
	tree = Insert(1, tree);
	tree = Insert(6, tree);
	tree = Insert(5, tree);
	tree = Insert(7, tree);

	puts("Address\tElement");
	InOrderTraversal(tree);

	puts("I will delete 5, 6, 2, 4");	
	printf("positon\telem\tleft\tright\n");

	TBSTree p = Find(5, tree);
	printf("%p\t%d\t%p\t%p\n", p, p->elem, p->left, p->right);	

	tree = Delete(5, NULL, tree);
	p = Find(6, tree);
	printf("%p\t%d\t%p\t%p\n", p, p->elem, p->left, p->right);	
	
	tree = Delete(6, NULL, tree);
	p = Find(7, tree);
	printf("%p\t%d\t%p\t%p\n", p, p->elem, p->left, p->right);	

	tree = Delete(2, NULL, tree);
	p = Find(1, tree);
	printf("%p\t%d\t%p\t%p\n", p, p->elem, p->left, p->right);	

	tree = Delete(4, NULL, tree);
	p = Find(7, tree);
	printf("%p\t%d\t%p\t%p\n", p, p->elem, p->left, p->right);	



	exit(EXIT_SUCCESS);
}

