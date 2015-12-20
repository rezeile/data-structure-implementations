/* 
 * A LIFO stack that uses an raw array as its 
 * internal implementation.
 * Author: Eliezer Abate
 * Last Edit: December 19 2015 15:12 PST
 */

#ifndef _AR_STACK_H
#define _AR_STACK_H

#include <iterator>
#include <iostream>
#include <exception>

/* forward declaration to allow use in StackIterator */
template<typename T>
class Stack;

/* StackIterator */
template<typename T>
class StackIterator {
public:
  /* constructor */
  StackIterator (T *&items, int pos) : _pos(pos), _items(items) {}
  
  /* define != operator for Bag */
  bool operator != (StackIterator<T> other) {
  	 return _pos != other._pos;
  }

  bool operator == (StackIterator<T> other) {
  	 return _pos == other._pos;
  }

  /* overload ++ operator */
  StackIterator& operator++ () {
  	++_pos;
  	return *this;
  }

  /* overload the dereference * operator */
  T operator* () {
	return _items[_pos];
  }

private:
	int _pos; /* position */
	T *_items;
};

/* utility function: resize 
 * ------------------------
 * This function resizes the internal array to a new size
 * specified the variable new_sz.
 */
template<typename T>
void resize(T *&items,int old_sz, int new_sz) {
	/* copy elements into new array */
	int sz = old_sz < new_sz ? old_sz : new_sz;
	T *new_items = new T[new_sz];
	for(int i = 0; i < sz; i++) {
		new_items[i] = items[i];
	}
	delete[] items; /* free memory */
	items = new_items;
}

/*
 * class: Stack
 * ------------
 * Defines the public member functions that this
 * class exports. 
 */
static const int kInitialSize = 100;
template<typename T>
class Stack {
	public:
		Stack();
		~Stack();
		void push(T a);
		T pop();
		bool empty();
		StackIterator<T> begin() {
  			return StackIterator<T>(items,0);
  		}
  		StackIterator<T> end() {
  			return StackIterator<T>(items,top);
  		}
	private:
		T *items;
		int top; /* index of next top element [also serves as the count] */
		         /* if top == 0, the stack is empty */
		int cap;
};

/* class definition */

/* 
 * Constructor
 * -----------
 * Initializes the top of the index
 * to -1 to signal that the stack 
 * is empty. 
 */
template<typename T>
Stack<T>::Stack() {
	items = new T[kInitialSize];
	top = 0; /* initialize to empty */
	cap = kInitialSize; /* initial size */
}

/* 
 * Destructor 
 * ----------
 */
template<typename T>
Stack<T>::~Stack() {
	delete[] items;
}

/* 
 * Push 
 * ----
 * Adds an item to the top of the stack. Internally this places the item
 * at the end of the array, which is denoted by the variable top. If the capacity
 * of the internal array is exceeded we double the internal array capacity.
 * We note that this operation takes constant amortized time. By amortized 
 * we mean that the average cost over a sequence of push operations is 
 * constant even though in the worst case a push operation might take time 
 * proportional to n, where n is the maximum size of the internal array. 
 * The amortized constant time is a consequence of the following fact: For 
 * a push operation to cost O(n), it must have been the case that there were 
 * n constant (O(1)) push operations that prededed it and filled up the array. 
 * Consider the following illustration, where we start out with an empty internal 
 * array of size 4.
 *
 *
 * |__|__|__|__|
 *
 *
 * Now observe the state of the array after four push operations:
 *
 * operation       cost
 * ---------       ----
 * push(4);        O(1)
 * push(5);        O(1)
 * push(8);        O(1)
 * push(2);        O(1)
 *
 * |_4_|_5_|_8_|_2_|
 *
 * The next push operation will require a doubling of the internal array prior
 * to the push which takes constant time. We know the doubling will take time
 * proportional to the capacity of the array (in this case 4). Thus we have
 * 
 * operation       cost
 * ---------       ----
 * push(3)         O(n) [where n is the array capacity]
 *
 *
 * But considering the general case entire sequence of operations, push(4) 
 * through push(3) we have the following average over the first n + 1 pushes:
 *
 * [O(1) + O(1) + ... + O(1) + O(n)] / (n + 1) = O(1)
 *
 * This is what we mean when we say push has a constant amortized cost.
 */
template<typename T>
void Stack<T>::push(T a) {
	/* check if there is space (i.e. whether top + 1 is capacity, since top is 0-indexed) */
	if((top + 1) == cap) {
		/* increase the array capacity */
		resize(items,cap, 2 * cap);
		cap *= 2;
	}
	/* add to new position */
	items[top++] = a;
}

/*
 * Pop
 * ---
 * This operation allows the cient to pop an element from the top of the stack.
 * This is internally represented by decrementing the value of our variable
 * top, which is the index of the top most element in the array. Since a sequence
 * of pop operations can result in a sparsely populated array, this operation 
 * halves the internal array capacity when it is not being adequately utilized 
 * (i.e. it's 1/4 full.). The pop operation takes constant amortized 
 * time, meaning the halving of the array occurs very infrequently compared to 
 * pop operations that take O(1) time. This operation also throws an exception 
 * if pop is called on an empty stack.
 *
 * Note that our choice of halving the array when it is a fourth of its initial 
 * capacity is not arbitrary. If you think about it for a second, if we halved
 * the array when it was 'half' its capacity, halving it would essentially 
 * leave the resulting array full. Thus, by halving the array when it is a 
 * half full, we can accomodate a number of push and pop operations in the 
 * resulting array before having to resize again.
 */
 template <typename T>
 T Stack<T>::pop() {
 	if(this->empty()) {
 		throw "Stack Is Empty";
 	} else {
 		/* check for resize */
 		/* note the number of items in the internal array is precisely 'top' */
 		if(top <= cap/4) {
 			resize(items,cap,cap/2);
 			cap = cap/2;
 		}
 		return items[--top];
 	}
 }

 /*
  * Empty
  * -----
  * Returns true if stack is empty, false
  * otherwise.
  */
  template <typename T>
  bool Stack<T>::empty() {
  	return top == 0;
  }
#endif
