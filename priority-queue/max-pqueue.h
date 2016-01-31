/*
 * A maximum priority queue ...
 *
 * Author: Eliezer Abate
 * Last Edit: Sat Jan 30 2016
 */

#ifndef _MAX_PQUEUE_H
#define _MAX_PQUEUE_H

#include <iterator>
#include <iostream>
#include <exception>

/* Begin class definition */
template<typename T>
class MaxPQueue {
public:
	MaxPQueue();
	~MaxPQueue();
	void insert(T a);
	T max();
	T delMax();
private:
};

#endif
