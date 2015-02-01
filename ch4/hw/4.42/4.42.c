
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef enum {
	TRUE, FALSE
} status;

struct BTreeNode;
typedef struct BTreeNode* PtrToNode;
typedef PtrToNode BTree;

struct BTreeNode {
	ElementType elem;
	struct BTreeNode *left;
	struct BTreeNode *right;
};

void VisitNode(PtrToNode p) {
	printf("%d ", p->elem);
}

int IsNULL(BTree tr) {
	return tr == NULL;
}

status Isomorphic(BTree tr1, BTree tr2) {
	if (IsNULL(tr1) && IsNULL(tr2))
		return TRUE;
	else if ((IsNULL(tr1) && !IsNULL(tr2)) || 
					 (!IsNULL(tr1) && IsNULL(tr2)))
		return FALSE;
	else {
		if (tr1->elem == tr2->elem) {
			status s1 = Isomorphic(tr1->left, tr2->left);
			status s2 = Isomorphic(tr1->right, tr2->right);
			status case1 = s1 == TRUE && s2 == TRUE;

			status s3 = Isomorphic(tr1->left, tr2->right);
			status s4 = Isomorphic(tr1->right, tr2->left); 
			status case2 = s3 == TRUE && s4 == TRUE;

			return case1 || case2;
		} else 
			return FALSE;
	}
}




