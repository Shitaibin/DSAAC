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

BSTree FindK2Position(int value, BSTree tr) {
	return Find(value, tr);
}

void InOrder1(BSTree tr, BSTree stopnode) {
	if (tr) {
		if (tr == stopnode)
			return;

		if (tr->left)
			InOrder1(tr->left, stopnode);
		printf("%d ", tr->elem);
		if (tr->right)
			InOrder1(tr->right, stopnode);
	}
}

void PrintKeys1(BSTree tr1, BSTree tr2) {
	InOrder1(tr1->right, tr2);
	InOrder(tr2->left);
	puts("");
}

void PrintKeys2(BSTree root, BSTree tr1, BSTree tr2) {
	InOrder(tr1->right);
	InOrder1(root, tr1);
	InOrder1(root->right, tr2);
	InOrder(tr2->left);
	puts("");
}

int main()
{
	puts("we use exercise 4.31 to create a bstree, so ...");
	unsigned int n;
	puts("Input the height: ");
	scanf("%u", &n);
	unsigned int size = (1 << (n+1)) - 1;
	printf("size = %u\n", size);
		
	BSTree tree = NULL;
	int i;
	tree = BuildPerfectlyBalancedBT(tree, 1, size);
	
	InOrderTraverse(tree);
	
	/* 4.32 */
	printf("now input k1 and k2: ");
	int k1, k2;
	scanf("%d%d", &k1, &k2);
	
	Position p1 = Find(k1, tree);
	if (p1) {
		Position p2 = FindK2Position(k2, p1);
		if (p2) {
			// p2 under p1
			PrintKeys1(p1, p2);	
		} else {
			// p2 and p1 in different branch
			p2 = Find(k2, tree);
			PrintKeys2(tree, p1, p2);
		}	
	}	
	exit(EXIT_SUCCESS);
}

