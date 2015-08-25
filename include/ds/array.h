#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
	T *a;
	int l;

public:
	Array(); // Default constructor
	Array(int len);
	~Array();
	Array<T>& operator=(Array<T> &b);	// Copy constructor
	T& operator[](int i);
	int length();
};

#include "../../src/Array.cpp"

#endif
