#ifndef LISTS_H
#define LISTS_H

#include "./array.h"

template <class T>
class IList {
public:
	virtual ~IList() {}

	// Pure virtual methods.
	// Must be defined in implementing classes
	virtual int size() = 0;
	virtual T get(int i) = 0;
    virtual T set(int i, T x) = 0;
	virtual void add(int i, T x) = 0;
	virtual T remove(int i) = 0;
};


template <class T>
class ArrayStack : public IList<T> {
	Array<T> a;
	int n = 0;

	void resize();

public:
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);
};


template <class T>
class FastArrayStack : public IList<T> {
	Array<T> a;
	int n = 0;

	void resize();

public:
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);
};


template <class T>
class ArrayDeque : public IList<T>{
	Array<T> a;
	int j;
	int n;

	void resize();

public:
	int size();
	T get(int i);
	T set(int i, T x);
	void add(int i, T x);
	T remove(int i);
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



#include "../../src/lists/ArrayStack.cpp"
#include "../../src/lists/FastArrayStack.cpp"
#include "../../src/lists/ArrayDeque.cpp"
#include "../../src/lists/DualArrayDeque.cpp"

#endif



