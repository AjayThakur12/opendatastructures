/**
* Balanced binary tree.
*
* In addition to adhering to the property of the BinarySearchTree,
* the Treap also obeys the heap property:
* At every node u except the root, u.parent.p < u.p
* This means that the node with the lowest priority will
* be the root node.
*
* The priority values are unique and assigned at random.
* This means that, unlike the BinarySearchTree, data to be
* stored in the tree doesn't have to be added in random order itself.
* However, it is still possible for the tree to be poorly balanced,
* for example if the smallest item also gets the smallest priority,
* resulting in a root node with no left branch. Nonetheless, in
* the average case this will perform better than the unbalanced
* BinarySearchTree.
*
* How do we keep track of the priorities to make sure new data
* gets a new unique priority? At the moment this is not tracked,
* but the range of random numbers is large so duplicates are
* unlikely in small trees.
*
* This tree shares a lot of functionality with the BinarySearchTree.
* If the later class were refactored, Treap could inherit from it.
*
* Performance:
*
* 				Worst case		Expected
*      add(x):     O(n)         O(log(n))
*   remove(x):     O(n)			O(log(n))
*     find(x):     O(n)			O(log(n))
*/

#include <stdlib.h>
#include <iostream>

#include "ds/binary_trees.h"
#include "ds/array_lists.h"


/**
* Start state:
*
*        {8,5}
*		/     \
*    {4,6}  {12,4}
*           /     \
*        {9,7}   {15,8}
*
* rotateLeft({8,5}):
*
*        {12,4}
*       /      \
*    {8,5}   {15,8}
*	/     \
* {4,6}  {9,7}
*
* Does the heap property still hold after a rotation has been performed?
* Rotations are performed specifically to maintain the heap property,
* as the initial addition is performed only to maintain the binary seach
* tree property.
*/
template <class T>
void Treap<T>::rotateLeft(BTNode<T>* u){
	BTNode<T>* w = u->right;
	w->parent = u->parent;
	if (w->parent != nullptr){
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nullptr){
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == root){
		root = w;
		root->parent = nullptr;
	}
}

/**
* Start state:
*
*        {12,4}
*       /      \
*    {8,1}   {15,8}
*	/     \
* {4,2}  {9,6}
*
* rotateRight({12,4}):
*
*        {8,1}
*		/     \
*    {4,2}  {12,4}
*           /     \
*        {9,6}   {15,8}
*
*/
template <class T>
void Treap<T>::rotateRight(BTNode<T>* u){
	BTNode<T>* w = u->left;
	w->parent = u->parent;
	if (w->parent != nullptr){
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nullptr){
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == root){
		root=w;
		root->parent = nullptr;
	}
}


template <class T>
int Treap<T>::size(){
	return n;
}

/**
* Add x as a new node in the appropriate leaf position.
* Then use rotations to maintain the heap property.
* This should ensure that the tree stays balanced.
*/
template <class T>
bool Treap<T>::add(T x){
	/// Copied from BinarySearchTree
	BTNode<T>* previousNode = nullptr;
	BTNode<T>* currentNode = root;

	// Search for x in the tree
	while (currentNode != nullptr) {
		if (x == currentNode->x){
			return false;	// We found x, don't need to do anything else
		} else if (x < currentNode->x) {
			// Go down the left branch
			previousNode = currentNode;
			currentNode = currentNode->left;
		} else if (x > currentNode->x) {
			// Go down the right branch
			previousNode = currentNode;
			currentNode = currentNode->right;
		}
	}

	// If we got here, we did not find x,
	// We can add it in as a leaf of previousNode
	TreapNode<T>* u = new TreapNode<T>(x, rand());
	u->parent = previousNode;

	// Special case if this is the first entry
	if (previousNode == nullptr){
		root = u;
	} else if (x < previousNode->x){
		previousNode->left = u;
	}
	else if (x > previousNode->x){
		previousNode->right = u;
	}
	///

	// Rebalance the tree by bubbling up
	while (u->parent != nullptr && static_cast<TreapNode<T>*>(u->parent)->p > u->p){
		if (u->parent->right == u){
			rotateLeft(u->parent);
		} else {
			rotateRight(u->parent);
		}
	}
	if (u->parent == nullptr){
		root = u;
	}

	n++;
	return true;
}

template <class T>
T Treap<T>::remove(T x){
	// First, find the node.
	BTNode<T>* currentNode = root;

	while (currentNode != nullptr){
		if (x == currentNode->x ){
			break;
		} else if (x < currentNode->x){
			currentNode = currentNode->left;
		} else if (x > currentNode->x){
			currentNode = currentNode->right;
		}
	}

	//Throw an exception if it's not found
	if (currentNode == nullptr){
		throw std::out_of_range("Could not find x for removal");
	}

	// Rotate this node until it has one or fewer child branches
	while (currentNode->left != nullptr || currentNode->right !=nullptr){
		if (currentNode->left == nullptr){
			rotateLeft(currentNode);
		} else if (currentNode->right == nullptr){
			rotateRight(currentNode);
		} else if (static_cast<TreapNode<T>*>(currentNode->left)->p < static_cast<TreapNode<T>*>(currentNode->right)->p){
			rotateRight(currentNode);
		} else {
			rotateLeft(currentNode);
		}
		if (root == currentNode){
			root = currentNode->parent;
		}
	}

	// Splice it out
	splice(currentNode);
	delete currentNode;

	n--;

	return x;
}


// Exactly the same as BinarySearchTree
template <class T>
void Treap<T>::splice(BTNode<T>* removalNode){
	BTNode<T>* spliced;
	BTNode<T>* parent;

	if (removalNode->left != nullptr){
		spliced = removalNode->left;
	} else {
		spliced = removalNode->right;
	}

	if (removalNode == root){
		root = spliced;
		parent = nullptr;
	} else {
		parent = removalNode->parent;
		if (parent->left == removalNode){
			parent->left = spliced;
		} else {
			parent->right = spliced;
		}
	}
	if (spliced != nullptr){
		spliced->parent = parent;
	}
}

// Exactly same as binary search tree
template <class T>
T Treap<T>::find(T x){
	BTNode<T>* previousBigNode = nullptr;
	BTNode<T>* currentNode = root;

	// Search for x in the tree
	while (currentNode != nullptr) {
		if (x == currentNode->x){
			return x;	// We found x, don't need to do anything else
		} else if (x < currentNode->x) {
			// Go down the left branch
			previousBigNode = currentNode;
			currentNode = currentNode->left;
		} else if (x > currentNode->x) {
			// Go down the right branch
			currentNode = currentNode->right;
		}
	}

	if (previousBigNode == nullptr){
		// A couple of options here.
		// There may be no nodes larger than x.
		// Or the only node large might be the root.
		if (root != nullptr && root->x > x){
			return root->x;
		} else {
			throw std::out_of_range("No values larger than x in tree");
		}
	}
	return previousBigNode->x;
}


template <class T>
void Treap<T>::draw(){
	ArrayQueue<TreapNode<T>*> queue;
	queue.enqueue(static_cast<TreapNode<T>*>(root));

	int spacing = 40;

	//while(queue.size()){
	for (int i=0; i < 5; i++){
		ArrayQueue<TreapNode<T>*> level;
		// Dequeue everything from the queue into level
		while(queue.size()){
			level.enqueue(queue.dequeue());
		}

		while(level.size()){
			TreapNode<T>* node = level.dequeue();

			for (int i = 0; i<spacing; i++){
				std::cout << " ";
			}
			if (node != nullptr){
				std::cout << node->x;
				queue.enqueue(static_cast<TreapNode<T>*>(node->left));
				queue.enqueue(static_cast<TreapNode<T>*>(node->right));
			} else {
				std::cout << '_';
				queue.enqueue(nullptr);
				queue.enqueue(nullptr);
			}
			for (int i = 0; i<spacing; i++){
				std::cout << " ";
			}
		}
		// Write each item in level with given spacing ahead of it
		// Put it's left and right nodes into the queue
		// If any are blank, put a nullptr in there

		// Halve the spacing for the next level
		std::cout << std::endl;
		spacing = spacing / 2;
	}
}

