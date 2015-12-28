/*
 * Implementation of a double-ended queue (deck), which supports
 * insertion and deletion from both ends. The following implementation
 * uses a doubly linked list as the underlying data structure and 
 * exports the following operations:
 *
 * pushLeft
 * pushRight
 * popLeft
 * popRight
 * size
 * empty
 *
 * Author: Eliezer Abate
 * Last Edit: Dec 27 23:00 PST 
 */

 #include <stddef.h>
 #include <exception>
 #include <iostream>

 #ifndef _DEQUE_HH
 #define _DEQUE_HH
 
 /* 
  * linked node 
  */
 template<typename T>
 struct Node {
 	T data;
 	Node *prev;
 	Node *next;
 };

/*
 * class: Deque
 * ------------
 */
 template<typename T>
 class Deque {
 public:
   Deque();
   ~Deque();
   void pushLeft(T item);
   void pushRight(T item);
   T popLeft();
   T popRight();
   int size();
   bool empty();
   void print();
 private:
   Node<T> *l_head;
   Node<T> *r_head;
   int count;
 };

/*
 * constructor
 */
 template<typename T>
 Deque<T>::Deque() {
   l_head = NULL;
   r_head = NULL;
   count = 0;
 }

/*
 * destructor
 */
 template<typename T>
 Deque<T>::~Deque() {
   Node<T> *cur = l_head;
   while(cur != NULL) {
     Node<T> *next = cur->next;
   	 delete cur;
   	 cur = next;
   }
 }

/*
 * member function: pushLeft
 * -------------------------
 * Adds an item to the left
 * end of the double ended 
 * queue.
 */
 template<typename T>
 void Deque<T>::pushLeft(T item) {
 	Node<T> *n = new Node<T>;
 	n->data = item; 
 	n->next = NULL; n->prev = NULL;
 	if(empty()) {
 		l_head = r_head = n;
 	} else {
 		l_head->prev = n;
 		n->next = l_head;
 		l_head = n;
 	}
 	count++;
 }

/*
 * member function: pushRight
 * -------------------------
 * Adds an item to the right
 * end of the double ended 
 * queue.
 */
 template<typename T>
 void Deque<T>::pushRight(T item) {
 	Node<T> *n = new Node<T>;
 	n->data = item; 
 	n->next = NULL; n->prev = NULL;
 	if(empty()) {
 		l_head = r_head = n;
 	} else {
 		r_head->next = n;
 		n->prev = r_head;
 		r_head = n;
 	}
 	count++;
 }

/*
 * member function: popLeft
 * ------------------------
 * Removes an item from the left
 * end of the double ended queue.
 */
 template<typename T>
 T Deque<T>::popLeft() {
   	if(empty()) 
 		throw "cannot remove item from an empty queue";
 	T ret = l_head->data;
 	/* save old l_head */
 	Node<T> *del = l_head;
 	/* rewire pointers */
 	/* check if last element */
 	if (count == 1) {
 		l_head = r_head = NULL;
 	} else {
 		l_head = l_head->next;
 		l_head->prev = NULL;
 	}
 	/* delete old left head */
 	delete del;
 	count--;
 	return ret;
 }

/*
 * member function: popRight
 * ------------------------
 * Removes an item from the right
 * end of the double ended queue.
 */
 template<typename T>
 T Deque<T>::popRight() {
 	if(empty()) 
 		throw "cannot remove item from an empty queue";
 	T ret = r_head->data;
 	/* save old right head */
 	Node<T> *del = r_head;
 	/* rewire pointers */
 	if(count == 1) {
 		r_head = l_head = NULL;
 	} else {
 		r_head = r_head->prev;
 		r_head->next = NULL;
 	}
 	/* delete old left head */
 	delete del;
 	count--;
 	return ret;
 }

/*
 * member function: size
 * ------------------------
 * Returns the number of 
 * elements in the double 
 * ended queue.
 */
 template<typename T>
 int Deque<T>::size() {
 	return count;
 }

/*
 * member function: empty
 * ----------------------
 * Returns true if the 
 * deque is empty, false 
 * otherwise.
 */
 template<typename T>
 bool Deque<T>::empty() {
 	return count == 0;
 }

/*
 * member function: print
 * ----------------------
 * prints out the items of 
 * the deque.
 */
 template<typename T>
 void Deque<T>::print() {
 	if(empty()) {
 		std::cout << "deque is empty!" << std::endl;
 	} else {
 		Node<T> *cur = l_head;
 		std::cout << "[";
 		while(cur != NULL) {
 			if(cur->next != NULL)
 				std::cout << cur->data << ",";
 			else 
 				std::cout << cur->data;
 			cur = cur->next;
 		}
 		std::cout << "]" << std::endl;
 	}
 }



 #endif 