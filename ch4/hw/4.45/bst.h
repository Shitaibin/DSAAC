#ifndef _BST_H

#define ElementType int

struct TBSTNode;
typedef struct TBSTNode *Position;
typedef Position TBSTree;

struct TBSTNode
{
	ElementType elem;
	TBSTree left;
	TBSTree right;
	unsigned int leftthread;
	unsigned int rightthread;
};

TBSTree MakeEmpty(TBSTree tr);
Position Find(ElementType x, TBSTree tr);
Position FindMin(TBSTree tr);
Position FindMax(TBSTree tr);
TBSTree Insert(ElementType x, TBSTree tr);
TBSTree Delete(ElementType x, Position parent, TBSTree tr);
ElementType Retrieve(Position P);
ElementType DeleteMin(TBSTree tr);

void FatalError(const char* str);
#endif // _BST_H


