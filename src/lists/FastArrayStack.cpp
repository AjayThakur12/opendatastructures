/**
* Small variation on ArrayStack making use of C++ std library
* features for efficient movement of data.
*/

#include "ds/lists.h"

template <class T>
void FastArrayStack<T>::resize(){
	Array<T> b(std::max(2*n, 1));
	std::copy(&a[0], &a[0]+n, &b[0]);	// Need to work with pointers here
	a = b;
}


template <class T>
int FastArrayStack<T>::size(){
	return n;
}


template <class T>
T FastArrayStack<T>::get(int i){
	return a[i];
}


template <class T>
T FastArrayStack<T>::set(int i, T x){
	T y = a[i];
	a[i] = x;
	return y;
}


template <class T>
void FastArrayStack<T>::add(int i, T x){
	if (n+1 > a.length()) resize();
	std::copy_backward(&a[i], &a[0]+n, &a[0]+(n+1));
	a[i] = x;
	n++;
}


template <class T>
T FastArrayStack<T>::remove(int i){
	T x = a[i];
	for (int j = i; j < n-1; j++){
		a[j] = a[j+1];
	}
	n--;
	if (a.length() >= 3*n) resize();

	return x;
}

