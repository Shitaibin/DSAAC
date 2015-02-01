#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "avltree.h"

void LevelOrder(AvlTree root)
{
	std::queue<AvlTree> que;
	while (!que.empty())
		que.pop();

	if (root)
		que.push(root);

	while (!que.empty())
	{
		AvlTree node = que.front();
		que.pop();
		printf("%d ", node->elem);
		if (node->left)
			que.push(node->left);
		if (node->right)
			que.push(node->right);
	}
	puts("");
}

void InOrder(AvlTree root)
{
	if (root->left)
		InOrder(root->left);
	printf("%d ", root->elem);
	if (root->right)
		InOrder(root->right);
}
	
int main()
{
	AvlTree tree = NULL;
	tree = Insert(1, tree);
	tree = Insert(2, tree);
	tree = Insert(3, tree);
	tree = Insert(4, tree);
	LevelOrder(tree);
	InOrder(tree);
	puts("");
	
	tree = Insert(5, tree);
	
	LevelOrder(tree);
	InOrder(tree);
	puts("");
	exit(EXIT_SUCCESS);
}	
	
	
