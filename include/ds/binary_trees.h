#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <sstream>
#include <string>

#include "./interfaces/sortedset.h"

template <class T>
class BTNode {
public:
	T x;
	BTNode<T>* parent;
	BTNode<T>* left;
	BTNode<T>* right;

	BTNode(){};
	BTNode(T _x): x(_x), parent(nullptr), left(nullptr), right(nullptr) {}
};


template <class T>
class TreapNode: public BTNode<T> {
public:
	int p;

	TreapNode(){}
	TreapNode(T _x, int _p): p(_p){
		// Can I just delegate these calls to BTNode constructor?
		this->x = _x;
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}

	std::string toString(){
		std::ostringstream ss;
		ss << "{" << this->x << "}";
		return ss.str();
	}
};


template <class T>
class RecursiveBinaryTree {
	BTNode<T>* root;

public:
	int depth(BTNode<T>* u);	// How many steps from u to root
	int height(BTNode<T>* u);	// Distance from this node to its furthest descendant
	int size(BTNode<T>* u);	// How many nodes under this one (inclusive)
};


template <class T>
class BinarySearchTree: public ISortedSet<T>{
	BTNode<T>* root;

	BTNode<T>* smallestNodeInSubtree(BTNode<T>* startNode);
	BTNode<T>* largestNodeInSubtree(BTNode<T>* startNode);
	BTNode<T>* findSmallerParent(BTNode<T>* node);
	void splice(BTNode<T>* removalNode);

public:
	BinarySearchTree(): root(nullptr) {}

	int size();
	bool add(T x);
	T remove(T x);
	T find(T x);	// return smallest number that is greater than or equal to x
	T secondLargest();
	T nthLargest(int n);
	void draw();
};


template <class T>
class Treap: public ISortedSet<T>{
	BTNode<T>* root;
	int n = 0;

	void rotateLeft(BTNode<T>*);
	void rotateRight(BTNode<T>*);
	void splice(BTNode<T>* removalNode);

public:
	Treap(): root(nullptr) {}

	int size();
	bool add(T x);
	T remove(T x);
	T find(T x);
	void draw();
};

#include "../../src/binarytrees/RecursiveBinaryTree.cpp"
#include "../../src/binarytrees/BinarySearchTree.cpp"
#include "../../src/binarytrees/Treap.cpp"

#endif
