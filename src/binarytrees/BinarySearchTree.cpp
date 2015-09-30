/**
* Simple, unbalanced binary tree.
*
* Because this tree doesn't attempt to rebalance itself,
* numbers must be added in a non-sorted order. Otherwise,
* it will just be a linear list with no branching.
*
* The only property this tree guarantees is that for any node u
* containing value x, the values in the u->left branch are lower than x,
* and the values in the u->right branch are greater than the x.
*
* This property allows efficient searching for a value, as at any node,
* only the left OR right node need be explored to find any value.
* The best case performance of find(x) is O(log(n)). However,
* because the tree can become unbalanced as items are added and removed,
* the worst case performance is O(n) as the tree approaches a linked list.
*
* Performance:
*
* 				Worst case		Best case*
*      add(x):     O(n)         O(log(n))
*   remove(x):     O(n)			O(log(n))
*     find(x):     O(n)			O(log(n))
*
* * Best case can only really be achieved if data is added in random
* order and there are no further deletions or additions to the tree
*/

#include <stdexcept>
#include "ds/array_lists.h"
#include "ds/binary_trees.h"

/**
* It would be possible to return size in O(1) time
* by returning an integer member variable which is
* incremented during calls to add() and decremented
* during calls to remove().
*
* This implementation instead traverses the tree counting
* each node in turn, taking O(n) time. It is implemented
* this way to show how a breadth-first search can be applied
* to the tree using a queue. With this approach, the immediate
* children of each node are visited before any deeper descendants.
* By swapping the queue for a stack, a depth first queue is used instead,
* in which case the left-most tree is visited first, then ascended until
* a right branch is hit, repeating until all nodes have been visited.
*/
template <class T>
int BinarySearchTree<T>::size(){
	ArrayQueue<BTNode<T>*> queue;
	int counter = 0;

	queue.enqueue(root);

	while (queue.size()){
		BTNode<T>* current = queue.dequeue();
		if (current->left != nullptr){
			queue.enqueue(current->left);
		}
		if (current->right != nullptr){
			queue.enqueue(current->right);
		}

		counter++;
	}

	return counter;
}

/**
* If we don't have a root node, add this as the root node
* If we do have a root node and x is smaller than root, look left
*   if it's bigger, look right
* Keep doing that until we find a node with no children
* Add x to the left or right of that node as appropriate
* If we encounter a node containing x at any point, abort and return false
*/
template <class T>
bool BinarySearchTree<T>::add(T x){
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

	// Special case if this is the first entry
	BTNode<T>* xNode = new BTNode<T>(x);
	xNode->parent = previousNode;

	if (previousNode == nullptr){
		root = xNode;
	} else if (x < previousNode->x){
		previousNode->left = xNode;
	}
	else if (x > previousNode->x){
		previousNode->right = xNode;
	}


	return true;
}


template <class T>
T BinarySearchTree<T>::remove(T x){
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

	// If it has one child, make that child the new left/right of parent as appropriate
	// If it has no children do the same, it will just be noops with nullptrs
	// If it has two children, the smallest value in the right subtree replaces it
	if (currentNode->left == nullptr || currentNode->right == nullptr){
		splice(currentNode);
		delete currentNode;
	} else {
		BTNode<T>* smallestToRight = smallestNodeInSubtree(currentNode->right);
		// To avoid moving lots of nodes around, just move the data and delete the smallest by splice
		currentNode->x = smallestToRight->x;
		// Now we can just remove the smallestToRightNode
		splice(smallestToRight);
		delete smallestToRight;	// Probably need a destructor here to remove reference to parent
	}

	return x;
}


/**
* May be slightly different from the find in add,
* as here, if we don't find x,
* we want to return the value from the last node
* that was bigger than x, not just the last node
* seen.
*
* This looks to me like it has a bug where it won't work
* if there's only one node in the tree
*/
template <class T>
T BinarySearchTree<T>::find(T x){
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
void BinarySearchTree<T>::splice(BTNode<T>* removalNode){
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

template <class T>
BTNode<T>* BinarySearchTree<T>::smallestNodeInSubtree(BTNode<T>* startNode){
	BTNode<T>* previousNode = nullptr;
	BTNode<T>* currentNode = startNode;

	while (currentNode != nullptr){
		previousNode = currentNode;
		currentNode = currentNode->left;
	}

	return previousNode;
}

template <class T>
BTNode<T>* BinarySearchTree<T>::largestNodeInSubtree(BTNode<T>* startNode){
	BTNode<T>* previousNode = nullptr;
	BTNode<T>* currentNode = startNode;

	while (currentNode != nullptr){
		previousNode = currentNode;
		currentNode = currentNode->right;
	}

	return previousNode;
}


template <class T>
T BinarySearchTree<T>::secondLargest(){
	// Find the largest by going right at each step
	BTNode<T>* largestNode = largestNodeInSubtree(root);

	if (largestNode->left == nullptr){
		return largestNode->parent->x;
	} else {
		return largestNodeInSubtree(largestNode->left)->x;
	}
}

template <class T>
BTNode<T>* BinarySearchTree<T>::findSmallerParent(BTNode<T>* node){
	T currentValue = node->x;
	BTNode<T>* nextNode = node->parent;
	while (nextNode->x > currentValue){
		nextNode = nextNode->parent;
	}
	return nextNode;
}

template <class T>
T BinarySearchTree<T>::nthLargest(int n){
	// Find the largest by going right at each step
	BTNode<T>* nextLargestNode = largestNodeInSubtree(root);

	for (int i=n; i > 1; i--){
		if (nextLargestNode->left == nullptr){
			nextLargestNode = findSmallerParent(nextLargestNode);
		} else {
			nextLargestNode = largestNodeInSubtree(nextLargestNode->left);
		}
	}

	return nextLargestNode->x;
}


template <class T>
void BinarySearchTree<T>::draw(){
	ArrayQueue<BTNode<T>*> queue;
	queue.enqueue(root);

	int spacing = 60;


	//while(queue.size()){
	for (int i=0; i < 6; i++){
		ArrayQueue<BTNode<T>*> level;
		// Dequeue everything from the queue into level
		while(queue.size()){
			level.enqueue(queue.dequeue());
		}

		while(level.size()){
			BTNode<T>* node = level.dequeue();
			for (int i = 0; i<spacing; i++){
				std::cout << " ";
			}
			if (node != nullptr){
				std::cout << node->x;
				queue.enqueue(node->left);
				queue.enqueue(node->right);
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
