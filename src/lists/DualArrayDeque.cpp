/*
*
* Efficient removal at either end of the list using two ArrayStacks.
*
*         af ab
* _ _ _ a b | c d _ _ _  add(3,x)
* _ _ _ a b | c x d _ _  add(4,y)
* _ _ _ a b | c x y d _  remove(0)
* _ _ _ b c | x y d _ _
*
* In the last operation, the removal of element 'a' caused a rebalancing to
* ensure data is evenly split between the two ArrayStacks.
*
* In order to preserve the encapsulation of the data within the ArrayStacks,
* this implementation differs from that presented by Morin in that the balancing
* operation calls ArrayStack::add rather than directly writing to the array.
* As long as those calls are made such that the backing array grows at the end,
* this shouldn't affect performance.
*
* Performance:
*
*      get(i): O(1)
*    set(i,x): O(1)
*    add(i,x): O(min(i,n-i)), ie at worst half the array will need to be moved
*      remove: O(min(i,n-i)), ie at worst half the array will need to be moved
*/

#include "ds/lists.h"

/**
* If one of the ArrayStacks contains 3 or more times as much data as the other,
* move the data into two new ArrayStacks such that it is evenly distributed.
*/
template <class T>
void DualArrayDeque<T>::balance(){
	if (3 * front.size() < back.size() || 3 * back.size() < front.size()){
		// New stacks - could have memory implications if data set is large
		ArrayStack<T> af2;
		ArrayStack<T> ab2;

		int n = front.size() + back.size();

		int nf = n/2;
		// Consider looping backwards to avoid shifting data
		for (int i = 0; i < nf; i++){
			af2.add(nf - i - 1, get(i));
		}

		int nb = n - nf;
		// New data is added to end of array so should be fast
		for (int i = 0; i < nb; i++){
			ab2.add(i, get(nf+i));
		}

		front = af2;
		back = ab2;
	}
}


template <class T>
int DualArrayDeque<T>::size(){
	return front.size() + back.size();
}


template <class T>
T DualArrayDeque<T>::get(int i){
	if (i < front.size()) {
		return front.get(front.size() - i - 1);
	} else {
		return back.get(i - front.size());
	}
}


template <class T>
T DualArrayDeque<T>::set(int i, T x){
	if (i < front.size()) {
		return front.set(front.size() - i -1, x);
	} else {
		return back.set(i - front.size(), x);
	}
}


template <class T>
void DualArrayDeque<T>::add(int i, T x){
	if (i < front.size()){
		front.add(front.size() - i, x);
	} else {
		back.add(i - front.size(), x);
	}
	balance();
}


template <class T>
T DualArrayDeque<T>::remove(int i){
	T x;
	if (i < front.size()){
		x = front.remove(front.size() - i -1);
	} else {
		x = back.remove(i - front.size());
	}
	balance();
	return x;
}

