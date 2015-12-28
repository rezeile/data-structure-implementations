/* 
 * The following is an implementation of the Bag class, which is a data 
 * structure that simply collects a list of items whose internal 
 * representation or order does not really matter to the client. The Bag
 * data structure does not allow a client to remove items. A client 
 * can simply add items into the bag and when desired our client can also
 * iterate through the items in the bag. The following implementation uses
 * an array to internally store the items of the bag.
 * 
 * Author: Eliezer Abate
 * Last Edit: December 13, 2015
 * Irvine, CA
 *
 * Sources/Further Reading
 * -----------------------
 * For a further exposition on this data structure, refer to Introduction to 
 * Algorithms (Third Edition), Chapter 1.3, by Robert Sedgewick and Kevin
 * Wayne.
 */

#ifndef _AR_BAG_H
#define _AR_BAG_H

#include <iterator> 

/* forward declaration to allow use in BagIterator */
template<typename T>
class Bag;

template<typename T>
class BagIterator {
public:
  /* constructor */
  BagIterator (T *&items, int pos) : _pos(pos), _items(items) {}
  
  /* define != operator for Bag */
  bool operator != (BagIterator<T> other) {
  	 return _pos != other._pos;
  }

  bool operator == (BagIterator<T> other) {
  	 return _pos == other._pos;
  }

  /* overload ++ operator */
  BagIterator& operator++ () {
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

static const int kInitialSize = 10;
/* class declaration */
template<typename T>
class Bag {
  public:
  	Bag();
  	~Bag();
  	void add(T a); /* add an item to the bag */
  	bool isEmpty();
  	int size();
  	BagIterator<T> begin() {
  		return BagIterator<T>(items,0);
  	}
  	BagIterator<T> end() {
  		return BagIterator<T>(items,count);
  	}
  private:
  	int count;
  	int cap; /* internal array capacity */
  	T *items; /* array that will hold bag items internally */
};

/* 
 * Constructor
 * -----------
 * This constructor allocates memory for the initial internal array that will
 * store the Bag items. 
 */
template<typename T>
Bag<T>::Bag() {
	items = new T[kInitialSize];
  count = 0; /* initialize count */
  cap = kInitialSize;
}

/*
 * Destructor 
 * ----------
 */
template<typename T>
Bag<T>::~Bag() {
	delete[] items;
}

/* 
 * Add
 * ---
 * This member function allows a client to add an item into the bag. If the 
 * internal array is full on this call (i.e. cap == count), the internal
 * array's capacity will first be expanded (doubled), and then the item
 * will be added to the array.
 *
 * Running Time:
 * Including the resize steps, this operation has a constant [O(1)]
 * amortized costs over the sequence of add calls.
 *
 */
template<typename T>
void Bag<T>::add(T a) {
	/* check for resize */
	if(count == cap) {
		/* allocate new array of size 2 * cap */
		T *nw_arr = new T[2 * cap];
		/* copy old array values */
		for(int i = 0; i < count; i++) {
			nw_arr[i] = items[i];
		}
		/* release resources associated with old array and assign it new array */
		delete[] items;
		items = nw_arr;
	}
	/* add to index [count] */
	items[count] = a;
	count++;
}

/*
 * isEmpty
 * -------
 * Returns true if the Bag contains no items and false otherwise. 
 * 
 * Running Time:
 * The isEmpty() operation runs in constant Theta(1) time.
 */
 template <typename T>
 bool Bag<T>::isEmpty() {
 	return count == 0;
 }

 /*
  * size
  * -----
  * Returns the number of items that are currently in the bag.
  *
  * Running Time:
  * Theta(1)
  */
  template <typename T>
  int Bag<T>::size() {
  	return count;
  }
#endif
