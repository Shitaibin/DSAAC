#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

BSTree BuildPerfectlyBalancedBT(BSTree tree, 
																	unsigned int leftbound,
																	unsigned int rightbound) {
	if (leftbound > rightbound)
		return NULL;

	unsigned int mid = (leftbound + rightbound)/2;
	BSTree newnode = (BSTree) malloc(sizeof(struct BSTNode));
	if (newnode) {
		newnode->left = BuildPerfectlyBalancedBT(newnode, leftbound, mid-1);
		newnode->right = BuildPerfectlyBalancedBT(newnode, mid+1, rightbound);
		newnode->elem = mid;
	}	
	return newnode;
}

void InOrder(BSTree tr) {
	if (tr) {
		if (tr->left)
			InOrder(tr->left);
		printf("%d ", tr->elem);
		if (tr->right)
			InOrder(tr->right);
	}
}

void InOrderTraverse(BSTree tr) {
	printf("In order: ");
	InOrder(tr);
	puts("");
}

int main()
{
	unsigned int n;
	puts("Input the height: ");
	scanf("%u", &n);
	unsigned int size = (1 << (n+1)) - 1;
	printf("size = %u\n", size);
		
	BSTree tree = NULL;
	int i;
	tree = BuildPerfectlyBalancedBT(tree, 1, size);
	
	InOrderTraverse(tree);
	exit(EXIT_SUCCESS);
}

