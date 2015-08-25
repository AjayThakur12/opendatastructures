/*
* Efficient removal at either end of the list using a single array.
*
* Similar to the ArrayQueue, this uses modulo arthmetic to
* wrap data around an array.
*
*   _ _ _ _ _  (j=0, n=0)  add(0, 'a')
*   a _ _ _ _  (j=0, n=1)  add(1, 'b')
*   a b _ _ _  (j=0, n=2)  add(2, 'c')
*   a b c _ _  (j=0, n=3)  add(3, 'd')
*   a b c d _  (j=0, n=4)  remove(1)    Element is in 1st half of array,
*                                         so preceding elements are moved
*                                         forward and j is incremented
*   _ a c d _  (j=1, n=3)  add(1, 'e')  Element is in 1st half of array,
*                                         so decrement j, and shift first
*                                         half of elements back one
*   a e c d _  (j=0, n=4)  add(3, 'f')  Element is in 2nd half of array,
*                                         so shift later elements right
*   a e c f d  (j=0, n=5)  remove(3)    Element is in 2nd half of array,
*                                         so shift later elements left
*   a e c d _  (j=0, n=4)  add(1, 'g')  Element is in 1st half of array,
*                                         j was 0 so becomes 5-1=4 and
*                                         preceding elements are redistributed
*                                         with the element at (4+0+1)%5=0 moving
*                                         to (4+0)%5=4
*   g e c d a  (j=4, n=5)				Elements are ordered a,g,e,c,d
*
*
*
* Performance:
*
*      get(i): O(1)
*    set(i,x): O(1)
*    add(i,x): O(min(i,n-i)), ie at worst half the array will need to be moved
*      remove: O(min(i,n-i)), ie at worst half the array will need to be moved
*/

#include "ds/lists.h"

template <class T>
void ArrayDeque<T>::resize(){
	Array<T> b(std::max(1, 2*n));
	for (int k=0; k < n; k++){
		b[k] = a[(j+k) % a.length()];
	}
	a = b;
	j = 0;
}


template <class T>
int ArrayDeque<T>::size(){
	return n;
}


template <class T>
T ArrayDeque<T>::get(int i){
	return a[(j+i) % a.length()];
}


template <class T>
T ArrayDeque<T>::set(int i, T x){
	T y = a[(j+i) % a.length()];
	a[(j+i) % a.length()] = x;
	return y;
}


/*
* Operation is fast when i is close to 0 or close to n,
* as fewer elements will be moved in either direction.
*/
template <class T>
void ArrayDeque<T>::add(int i, T x){
	if (n+1 > a.length()) resize();
	if (i < n/2){
		j = (j==0) ? a.length() -1 : j-1;
		for (int k=0; k <= i-1; k++){
			a[(j+k) % a.length()] = a[(j+k+1) % a.length()];
		}
	} else {
		for (int k=n; k > i; k--){
			a[(j+k) % a.length()] = a[(j+k-1) & a.length()];
		}
	}
	a[(j+i) % a.length()] = x;
	n++;
}


/*
* Operation is fast when i is close to 0 or close to n,
* as fewer elements will be moved in either direction.
*/
template <class T>
T ArrayDeque<T>::remove(int i){
	T x = a[(j+i) % a.length()];
	if (i < n/2) {
		for (int k = i; k >0; k--){
			a[(j+k) % a.length()] = a[(j+k-1) % a.length()];
		}
		j = (j+1) % a.length();
	} else {
		for (int k = i; k < n-1; k++){
			a[(j+k) % a.length()] = a[(j+k+1) % a.length()];
		}
	}
	n--;
	if (3*n < a.length()) resize();

	return x;
}

