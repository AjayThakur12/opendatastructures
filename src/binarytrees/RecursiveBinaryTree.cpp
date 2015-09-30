/**
* Some example methods to show how a tree can be traversed
* using recursive and nonrecursive methods.
*/

#include "ds/binary_trees.h"

/**
* The number of nodes between this node and the
* root of the tree.
*
* By using a while loop rather than recursion,
* this avoids the problem of large trees causing
* stack overflow.
*/
template <class T>
int RecursiveBinaryTree<T>::depth(BTNode<T>* u){
	int d = 0;
	while(u != root){
		u = u->parent;
		d++;
	}
	return d;
}


/**
* The height of a node is the largest number
* of nodes on the way to a leaf in its subtree.
* If the node is the root, this gives the overall
* height of the tree.
*/
template <class T>
int RecursiveBinaryTree<T>::height(BTNode<T>* u){
	if (u == nullptr){
		return 0;
	}
	return 1 + max(height(u->left), height(u->right));
}

/**
* Recursive method to calculate size, ie
* the number of nodes in the tree. This could
* be better performed in O(1) time with a counter
* member variable that is modified during calls
* to add() and remove().
*/
template <class T>
int RecursiveBinaryTree<T>::size(BTNode<T>* u){
	if (u == nullptr){
		return 0;
	}
	return 1 + size(u->left) + size(u->right);
}
