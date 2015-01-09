#ifndef _BST_H

#define ElementType int

struct BSTNode;
typedef struct BSTNode *Position;
typedef Position BSTree;

struct BSTNode
{
	ElementType elem;
	BSTree left;
	BSTree right;
};

BSTree MakeEmpty(BSTree tr);
Position Find(ElementType x, BSTree tr);
Position FindMin(BSTree tr);
Position FindMax(BSTree tr);
BSTree Insert(ElementType x, BSTree tr);
BSTree Delete(ElementType x, BSTree tr);
ElementType Retrieve(Position P);
ElementType DeleteMin(BSTree tr);

void FatalError(const char* str);
#endif // _BST_H


