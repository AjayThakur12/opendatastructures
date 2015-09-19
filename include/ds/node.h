#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	T x;
	Node<T>* next;

	Node(T _x): x(_x), next(nullptr){}
};


template <class T>
class DNode {
public:
	T x;
	DNode<T>* next;
	DNode<T>* prev;

	DNode(T _x): x(_x), next(nullptr), prev(nullptr){}
};

#endif
