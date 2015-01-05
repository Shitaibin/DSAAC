#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <assert.h>
#include <stdlib.h>

#define ElementType int

struct AvlNode;
typedef struct AvlNode* AvlNodePtr;
typedef AvlNodePtr AvlTree;
typedef AvlNodePtr Position;
struct AvlNode {
	AvlTree left;
	AvlTree right;
	int height;
	ElementType elem;
};

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType elem, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType elem, AvlTree T);
AvlTree Delete(ElementType elem, AvlTree T);
inline ElementType Retrieve(Position p)
{
	assert(p != NULL);
	return p->elem;
}

inline static int Height(AvlTree T)
{
	return T == NULL ? -1 : T->height;
}

static int Max(const int numa, const int numb);
static AvlTree SingleRotateWithLeft(AvlTree T);
static AvlTree SingleRotateWithRight(AvlTree T);
static AvlTree DoubleRotateWithLeft(AvlTree T);
static AvlTree DoubleRotateWithRight(AvlTree T);



#endif		// AVLTREE_H_



