/* 
 * A LIFO stack that uses an raw array as its 
 * internal implementation.
 * Author: Eliezer Abate
 * Last Edit: November 9 2015 15:12 PST
 */

#ifndef _AR_STACK_H
#define _AR_STACK_H

#include <exception>

/* utility functions */
template<typename T>
void incr_capacity(T *items,int old_sz) {
	/* copy elements into new array */
	T *new_items = new int[2 * old_sz];
	for(int i = 0; i < old_sz; i++) {
		new_items[i] = items[i];
	}
	delete[] items;
	items = new_items;
}
/* class declaration */
static const int ini_sz = 100;
template<typename T>
class Stack {
	public:
		Stack();
		~Stack();
		void push(T a);
		T pop();
		bool empty();
	private:
		T *items;
		int top;
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
	items = new int[ini_sz];
	top = -1; // initialize to empty
	arr_size = ini_sz;
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
 */
template<typename T>
void Stack<T>::push(T a) {
	/* check if there is space */
	int nxt_indx = top + 1;
	if(nxt_indx == (arr_size - 1)) {
		/* increase the array capacity */
		incr_capacity(items,arr_size);
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
