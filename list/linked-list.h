/*
 * The following class presents a singly-linked list that can store elements of
 * various types (i.e. its a templated class). The operations allowed by the 
 * list are the standard CRUD operations, create (the linked list), read a value
 * from a position in the linked list, update a value, and delete a value from 
 * the linked list. In addition we will also maintain member functions 'isEmpty' 
 * and 'size', which signify whether the linked list is empty and how many elements
 * it contains, respectively. 
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>
/* 
 * Small struct that will represent a node in the linked list 
 */
 template<typename T>
 struct Node {
 	T data;
 	Node *next;
 };
 
 template<typename T>
 class LinkedList {
 public:
 	/* creation and destruction */
 	LinkedList<T>();
 	~LinkedList<T>();
 	/* insertion */
 	void add_to_front(Node<T> *n);
 	void add_at_position(Node<T> *n, int pos);
 	/* deletion */
 	void remove_from_position(int n);
 	/* update by value */
 	void update_at_position(T data, int pos);
 private:
 	Node<T> *head;
 	int size;
 };

 /*
  * Constructor 
  * -----------
  */
  template<typename T>
  LinkedList::LinkedList<T>() {
  	/* allocate memory for inital node from free store */
  	head = new Node<T>;
  }

 #endif