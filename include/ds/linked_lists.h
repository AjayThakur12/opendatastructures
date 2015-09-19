#ifndef SLLIST_H
#define SLLIST_H

#include "./interfaces/deque.h"
#include "./interfaces/list.h"
#include "./interfaces/queue.h"
#include "./interfaces/stack.h"
#include "./node.h"

template <class T>
class SLList: public IStack<T>, public IQueue<T>{
	Node<T>* head;
	Node<T>* tail;
	int n = 0;

public:
	int size();

	// Stack methods: last in, first out
	void push(T x);
	T pop();

	// Queue methods: first in, first out
	void enqueue(T x);	// Add at tail
	T dequeue();		// Same as pop, remove from head
};


template <class T>
class DLList: public IDeque<T>, public IStack<T>, public IQueue<T>, public IList<T>{
	DNode<T> dummy;
	int n = 0;

	DNode<T>* getNode(int i);
	DNode<T>* addBefore(DNode<T> *w, T x);

public:
	DLList();

	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);

	void addFirst(T x);
	T removeFirst();
	void addLast(T x);
	T removeLast();

	void push(T x);
	T pop();

	void enqueue(T x);
	T dequeue();
};

#include "../../src/linkedlists/SLList.cpp"
#include "../../src/linkedlists/DLList.cpp"

#endif
