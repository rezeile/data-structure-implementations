/* 
 * A LIFO stack that uses a linked list as its 
 * internal implementation.
 * 
 * Author: Eliezer Abate
 * Last Edit: December 22 2015 12:40 PST
 */

#ifndef _LL_STACK_H
#define _LL_STACK_H

#include <iostream> /* for NULL ? */
#include <exception>

/* forward declaration to allow use in StackIterator */
template<typename T>
class Stack;

/* node for linked list */
template<typename T>
struct Node {
  T data;
  Node *next;
};

/*
 * class: Stack
 * ------------
 * Defines the public member functions that this
 * class exports. 
 */
template<typename T>
class Stack {
	public:
		Stack();
		~Stack();
		void push(T a);
		T pop();
		bool empty();
	private:
		Node<T> *head;
};

/* 
 * Constructor
 * -----------
 * Initializes the head of the linked list to NULL, signifiying that we start 
 * out with an empty list.
 */
template<typename T>
Stack<T>::Stack() {
	head = NULL;
}

/* 
 * Destructor 
 * ----------
 */
template<typename T>
Stack<T>::~Stack() {
	Node<T> *cur = head;
	while(cur != NULL) {
		Node<T> *next = cur->next;
		delete cur;
		cur = next;
	}
}

/* 
 * Push 
 * ----
 * Adds an item to the top of the stack. Internally we simply add an item to
 * the front of the linked list. Note that this operation takes O(1) time.
 */
template<typename T>
void Stack<T>::push(T a) {
	/* allocate a new Node */
	Node<T> *n = new Node<T>;
	n->data = a;
	n->next = head;
	head = n;
}

/*
 * Pop
 * ---
 * Removes an item from the top of the stack. This operation, just like the push,
 * also takes O(1) time.
 */
 template <typename T>
 T Stack<T>::pop() {
 	/* remove an item from the top of the list */
 	if(empty())
 		throw "Attempted to pop an element from an empty stack";
 	else {
 		T ret = head->data;
 		Node<T> *h_next = head->next;
 		head = h_next;
 		return ret;
 	}
 }

 /*
  * Empty
  * -----
  * Returns true if stack is empty, false
  * otherwise. O(1).
  */
  template <typename T>
  bool Stack<T>::empty() {
  	return head == NULL;
  }
#endif

