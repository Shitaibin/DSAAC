
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "avltree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (!T)
		return NULL;
	
	T->left = MakeEmpty(T->left);
	T->right = MakeEmpty(T->right);
	free(T);
	return NULL;
}

Position Find(ElementType elem, AvlTree T)
{
	if (!T)
		return NULL;	

	if (elem < T->elem)
	{
		Find(elem, T->left);
	} else if (elem > T->elem) {
		Find(elem, T->right);
	} else {
		return T;
	}
}
	
Position FindMin(AvlTree T)
{
	if (!T)
		return NULL;

	while (T->left)
		T = T->left;
	return T;
}

Position FindMax(AvlTree T)
{
	if (!T)
		return NULL;

	while(T->right)
		T = T->right;
	return T;
}


AvlTree MakeStackEmpty(std::stack<AvlTree> s) {
    AvlTree root = NULL;
		while (!s.empty()) {
        root = s.top();
				s.pop();
    }
		return root;
}

// @elem, value be inserted
// @t, an avltree
// @return, an avltree
AvlTree Insert(ElementType elem, AvlTree t) {
    // empty tree, create it 
		if (!t) {
        AvlTree root = (AvlTree) malloc(sizeof(struct AvlNode));
				if (!root) {
					perror("create avl tree failed");
					return NULL;
    		} else {
					root->elem = elem;
					root->height = 0;
					root->left = root->right = NULL;
					return root;
				}
		}

    std::stack<AvlTree> s;
    MakeStackEmpty(s);
    while (t)
    {
        s.push(t);
        if (elem < t->elem)
            t = t->left;
        else if (elem > t->elem)
            t = t->right;
        else {
            // exist, realse stack, not not adjust, return the old root
						return MakeStackEmpty(s);
        }
    }

		// a new node
    AvlTree leaf = (AvlTree) malloc (sizeof(struct AvlNode));
    if (leaf == NULL) {
        perror("malloc space for a new node");
        return NULL;
    } else {
        leaf->elem = elem;
        leaf->height = 0;
        leaf->left = leaf->right = NULL;
    }
   
		// inserting it 
    t = s.top();
    if (elem > t->elem)
        t->right = leaf;
    else
        t->left = leaf;

		// check out whether nodes in route should be rotate
    AvlTree tree; 
    while (!s.empty()) {
        tree = s.top();
        s.pop();
//        printf("insert:%d, route: %d\n", elem, tree->elem);
				if (Height(tree->left) - Height(tree->right) == 2) {
            if (elem < tree->left->elem)
						    tree = SingleRotateWithLeft(tree);
						else
                tree = DoubleRotateWithLeft(tree);
         		
						// i spent lots of time to fix it
						// make sure father's left or right pointer point to
						// the new sub-avltree, if it exist
						if (s.empty())
							break;
						AvlTree p = s.top();
						if (tree->elem > p->elem)
							p->right = tree;
						else
							p->left = tree;
						s.pop();
						s.push(p);
        } else if (Height(tree->right) - Height(tree->left) == 2) {
            if (elem > tree->right->elem)
                tree = SingleRotateWithRight(tree);
            else
                tree = DoubleRotateWithRight(tree);
         		if (s.empty())
							break;
						
         		AvlTree p = s.top();
						if (tree->elem > p->elem)
							p->right = tree;
						else
							p->left = tree;
						s.pop();
						s.push(p);
        }
    	tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
		}

    return tree;
}

AvlTree Delete(ElementType elem, AvlTree T)
{
	// Not right;
	// I don't know which rotate should be take
//	if (!T)
//		return NULL;
//
//	if (elem < T->elem)
//	{
//		T->left = Delete(elem, T->left);
//	} else if (elem > T->elem) {
//		T->right = Delete(elem, T->right);
//	}	else if (T->left && T->right) {
//	}
	return T;
}

static int Max(const int numa, const int numb)
{
	return numa > numb ? numa : numb;
}

static AvlTree SingleRotateWithLeft(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree newtree = oldtree->left;
	oldtree->left = newtree->right;
	newtree->right = oldtree;

	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(Height(newtree->left), oldtree->height) + 1;
	return newtree;
}

static AvlTree SingleRotateWithRight(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree newtree = oldtree->right;
	oldtree->right = newtree->left;
	newtree->left = oldtree;

	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtree->height, Height(newtree->right)) + 1;
	return newtree;
}

static AvlTree DoubleRotateWithLeft(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree oldtreeleft = oldtree->left;
	AvlTree newtree = oldtreeleft->right;
	oldtreeleft->right = newtree->left;
	newtree->left = oldtreeleft;
	oldtree->left = newtree->right;
	newtree->right = oldtree;
	
	oldtreeleft->height = Max(Height(oldtreeleft->left),
														Height(oldtreeleft->right)) + 1;
	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtreeleft->height, oldtree->height) + 1;
	return newtree;
}

static AvlTree DoubleRotateWithRight(AvlTree T)
{
	AvlTree oldtree = T;
	AvlTree oldtreeright = oldtree->right;
	AvlTree newtree = oldtreeright->left;
	oldtreeright->left = newtree->right;
	newtree->right = oldtreeright;
	oldtree->right = newtree->left;
	newtree->left = oldtree;

	oldtreeright->height = Max(Height(oldtreeright->left),
													Height(oldtreeright->right)) + 1;
	oldtree->height = Max(Height(oldtree->left), Height(oldtree->right)) + 1;
	newtree->height = Max(oldtree->height, oldtreeright->height) + 1;
	return newtree;
}






