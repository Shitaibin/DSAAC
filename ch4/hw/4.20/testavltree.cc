#include <stdio.h>
#include <queue>
#include "avltree.h"

void PrintInLevelOrder(AvlTree T)
{
	if (!T)
		return;

	std::queue<AvlTree> myqueue;
	while (!myqueue.empty())
		myqueue.pop();
	
	printf("Level Order: ");
	myqueue.push(T);
	while (!myqueue.empty())
	{
			T = myqueue.front();
			myqueue.pop();
			printf("%d ", T->elem);
			if (T->left)
				myqueue.push(T->left);
			if (T->right)
				myqueue.push(T->right);
	}

	puts("");
}

int main()
{
	AvlTree tree = NULL;
	int elem;
	int arr[100];
	int i = 0;
	while (scanf("%d", &elem) != EOF) {
		arr[i++] = elem;
		tree = Insert(elem, tree);
		PrintInLevelOrder(tree);
	}

	while (--i >= 0) {
		tree = Delete(arr[i], tree);
		PrintInLevelOrder(tree);
	}

	return 0;
}
		

