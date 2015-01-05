#ifndef _BST_H

#include "basic.h"

struct BSTNode;
typedef struct BSTNode *Position;
typedef Position BSTree;

struct BSTNode
{
	ElementType Element;
	BSTree Left;
	BSTree Right;
};

BSTree MakeEmpty(BSTree T);
Position Find(ElementType X, BSTree T);
Position FindMin(BSTree T);
Position FindMax(BSTree T);
BSTree Insert(ElementType X, BSTree T);
BSTree Delete(ElementType X, BSTree T);
ElementType Retrieve(Position P);
ElementType DeleteMin(BSTree T);

void FatalError(const char* str);
#endif // _BST_H


