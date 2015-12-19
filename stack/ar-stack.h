/* 
 * A LIFO stack that uses an raw array as its 
 * internal implementation.
 * Author: Eliezer Abate
 * Last Edit: December 19 2015 15:12 PST
 */

#ifndef _AR_STACK_H
#define _AR_STACK_H

#include <iterator>
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

/* utility functions */
template<typename T>
void increase_capacity(T *items,int old_sz) {
	/* copy elements into new array */
	T *new_items = new int[2 * old_sz];
	for(int i = 0; i < old_sz; i++) {
		new_items[i] = items[i];
	}
	delete[] items;
	items = new_items;
}
/* class declaration */
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
		int arr_size;
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
	items = new int[kInitialSize];
	top = 0; /* initialize to empty */
	arr_size = kInitialSize; /* initial size */
}

/* Destructor */
template<typename T>
Stack<T>::~Stack() {
	delete[] items;
}

/* 
 * Push 
 * ----
 * First increases the size if out of 
 * capacity. And then adds the element
 * to the top of the stack. 
 * 
 * Run Time: 
 *  The push operation is a simple 
 *  insert operation that takes a 
 *  constant O(1) amortized time.
 */
template<typename T>
void Stack<T>::push(T a) {
	/* check if there is space */
	int nxt_indx = top + 1;
	if(nxt_indx == (arr_size - 1)) {
		/* increase the array capacity */
		increase_capacity(items,arr_size);
		arr_size *= 2;
	}

	/* add to new position */
	items[++top] = a;
}

/*
 * Pop
 * ---
 * Pops an element from the top of the 
 * stack if there is an element, otherwise
 * returns null.
 *
 * Run Time: 
 *  The pop operation is a simple 
 *  insert operation that takes a 
 *  constant O(1) amortized time.
 *  What the fuck does that mean?
 */
 template <typename T>
 T Stack<T>::pop() {
 	if(!this->empty()) {
 		return items[top--];
 	}
 	throw "Stack Is Empty";
 }

 /*
  * Empty
  * -----
  * Returns true if stack is empty, false
  * otherwise.
  */
  template <typename T>
  bool Stack<T>::empty() {
  	return top == -1;
  }
#endif
