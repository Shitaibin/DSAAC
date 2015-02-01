#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct _ChildSibling;
typedef struct _ChildSibling* PtrToNode;
typedef PtrToNode BTree;

struct _ChildSibling {
	ElementType elem;
	struct _ChildSibling *child;
	struct _ChildSibling *sibling;
};

void VisitNode(PtrToNode p) {
	printf("%d ", p->elem);
}

void TraversalChildFirst(BTree tr) {
	if (!tr)
		return;

	if (tr->child)
		TraversalChildFirst(tr->child);
	VisitNode(tr);
	if (tr->sibling)
		TraversalChildFirst(tr->sibling);
}

void TraversalParentFirst(BTree tr) {
	if (!tr)
		return;

	VisitNode(tr);
	if (tr->child)
		TraversalParentFirst(tr->child);
	if (tr->sibling)
		TraversalParentFirst(tr->sibling);
}


