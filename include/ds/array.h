#ifndef ARRAY_H
#define ARRAY_H

#include <string>

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
	std::string draw();
};

#include "../../src/Array.cpp"

#endif
