/*
 * A maximum priority queue ...
 *
 * Author: Eliezer Abate
 * Last Edit: Thur Feb 4 2016 14:36 PST
 */

#ifndef _MAX_PQUEUE_H
#define _MAX_PQUEUE_H

#include <iterator>
#include <iostream>
#include <exception>

/* constants */
int DEFAULT_SIZE = 10;
int ROOT = 1;

/* begin class definition */
template<typename T>
class MaxPQueue {
public:
	MaxPQueue();
	~MaxPQueue();
	void insert(T a);
	T max();
	T delMax();
	bool isEmpty();
	int size();
private:
	T heap[]; /* array to maintain binary heap */
	int N;	 /* number of elements in pqueue */
	int cap; /* capacity */
};

/*
 * constructor
 * -----------
 * Default constructor which initializes the 
 * internal array to a constant default size. 
 */
template<typename T>
MaxPQueue<T>::MaxPQueue() {
	/* since our root will be at index 1, we 
	 * allocate one more space than the def-
	 * ault size, since we want to 1-index
	 * the array.
	 */
	heap = new T[DEFAULT_SIZE + 1]; 
	cap = DEFAULT_SIZE;
	N = 0;
};

/*
 * destructor
 * ----------
 * Deletes the memory allocated to 
 * store the heap.
 */
 template<typename T>
 MaxPQueue<T>::~MaxPQueue() {
 	delete[] heap;
 }

 /*
  * insert
  * ------------------------------------------
  * This routine inserts an element
  * with a particular priority 
  * into the priority queue. 
  * 
  * Note that the elements must be comparable
  * so that there is a way to rank the elements
  * by their priorities.
  */
  template<typename T>
  void MaxPQueue<T>::insert(T a) {
  	/* CODE goes here */
  }

  /*
   * max
   * ---
   * Returns the element with the highest priority
   * without removing the element fromt the 
   * priority queue.
   */
   template<typename T>
   T MaxPQueue<T>::max() {
   	 	if(!isEmpty()) return heap[ROOT];
   }

  /*
   * delMax
   * ------
   * Returns the element with the highest priority
   * and removes it from the priority queue.
   */
   template<typename T>
   T MaxPQueue<T>::delMax() {
       /* CODE goes here */
   }

  /*
   * isEmpty
   * --------
   * Returns true if the priority queue is empty.
   */
   template<typename T>
   bool MaxPQueue<T>::isEmpty() {
   	   return N == 0;
   }

  /*
   * size
   * --------
   * Returns the size of the priority queue.
   */
   template<typename T>
   int MaxPQueue<T>::size() {
   	   return N;
   }

#endif
