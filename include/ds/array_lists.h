#ifndef ARRAY_LISTS_H
#define ARRAY_LISTS_H

#include "./interfaces/deque.h"
#include "./interfaces/list.h"
#include "./interfaces/queue.h"
#include "./interfaces/stack.h"
#include "./array.h"

template <class T>
class ArrayStack : public IList<T>, public IStack<T> {
	Array<T> a;
	int n = 0;

	void resize();

public:
	// List methods
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);

	// Stack methods. Will delegate to list methods
	void push(T x);
	T pop();
};


template <class T>
class FastArrayStack : public IList<T>, public IStack<T> {
	Array<T> a;
	int n = 0;

	void resize();

public:
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);

	// Stack methods. Will delegate to list methods
	void push(T x);
	T pop();
};


template <class T>
class ArrayQueue : public IQueue<T> {
protected:
	Array<T> a;
	int j = 0;
	int n = 0;

	void resize();

public:
	int size();
	void enqueue(T x);
	T dequeue();
};


/**
* Since most of this functionality is implemented in ArrayQueue,
* it would be good to inherit from that class.
*/
template <class T>
class ArrayDeque : public ArrayQueue<T>, public IDeque<T>, public IStack<T>, public IList<T>{
public:
	int size();	// Would prefer to use the one defined in ArrayQueue
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
};


template <class T>
class DualArrayDeque : public IList<T>{
	ArrayStack<T> front;
	ArrayStack<T> back;

	void balance();

public:
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);
};



#include "../../src/arraylists/ArrayStack.cpp"
#include "../../src/arraylists/FastArrayStack.cpp"
#include "../../src/arraylists/ArrayQueue.cpp"
#include "../../src/arraylists/ArrayDeque.cpp"
#include "../../src/arraylists/DualArrayDeque.cpp"

#endif



