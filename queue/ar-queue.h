/*
 * Implementation of a templated FIFO First-Out (FIFO) queue, where elements
 * are removed from the queue in the order that they were inserted in. This
 * class supports the following operations:
 *   enqueue: insert an element in the queue
 *   dequeue: remove an element from the queue
 *   size:    number of elements in the queue
 *   isEmpty: returns true if the queue is empty 
 *   
 * We note that in this implementation, unlike our implementation of the bag
 * and stack classes, we will not allow the queue to be iterable. Traditional
 * queue's should only allow the insert (push) and delete (pop) operations.
 *
 * Author: Eliezer Abate (code.eliezer {at} gmail.com)
 * Last Updated: Dec 19 2015 18:42 (PST)
 */

#include <exception>

/* 
 * Class specification 
 * -------------------
 */
template<typename T>
class Queue {
  public:
    Queue<T>();
    ~Queue<T>();
    void enqueue(T a);
    T dequeue();
    int size();
    bool isEmpty();
    bool isFull();
  private:
  	void resize(int old_sz, int new_sz);
    T *items;  /* internal array holding queue elements */
    int cap;   /* array capacity */
    int count; /* number of elements in queue */
    int tail;  /* tail of queue to insert element*/
    int head;  /* index of element to remove */
};

/*
 * Constructor
 * -----------
 * 
 * O(1) time
 */
 static const int kInitialArraySize = 64;
 template<typename T>
 Queue<T>::Queue() {
   items = new T[kInitialArraySize];
   cap = kInitialArraySize;
   count = 0;
   tail = 0;
   head = 0;
 }

/* 
 * Destructor 
 * ----------
 * 
 * O(1) time
 */
 template<typename T>
 Queue<T>::~Queue() {
   delete[] items;
 }

/*
 * function: enqueue
 * -----------------
 * This function inserts an item into the queue. Observe that unlike the stack 
 * private member functions which kept track of just the top position of the 
 * stack, the queue requires that we keep two variables, one tail and one head. 
 * The head variable is the position of the next element we will remove from 
 * the queue and the tail position is the next available index during the 
 * enqueue operation. Consider the following illustration:
 * 
 * |__|__|__|__|
 *  ^
 *  |
 * head == tail
 *
 * Initially we have the following case, where head == tail, which signifies that
 * the queue is empty. Then after the following sequence of operations our internal 
 * array and its pointers look like the following:
 *
 *
 * enqueue(2);
 * enqueue(4);
 * enqueue(6);
 * 
 * |_2_|_4_|_6_|__|
 *  ^           ^
 *  |           |
 * head        tail
 *
 *
 * Note that head still points to the first element that we inserted into the queue, 
 * namely 2, and that tail points to the next available array index. It is worth
 * noting that in the following case, there is no available sport in the array since, 
 * if we add a new element then tail would be the same as head (after wrapping around
 * back to index 0).
 *
 * But the case where head == tail is already the signal that notifies us when the 
 * queue is empty, so if we allow the array to hold the 4th and last item then we 
 * would have the case where head == tail when the array is full. To prevent this 
 * from happening we limit the queue's capacity, for any array of size n, to be 
 * n - 1. In the above case when indices head, head + 1, tail - 1, have all been 
 * exausted, that becomes our signal that the queue is full. Furthermore, we have
 * an unambiguous test (head == tail + 1) that notifies us when this occurs. 
 * 
 * In summary:
 *
 * head == tail ==> Queue is empty
 * head == tail + 1 ==> Queue is full
 * Array size n ==> maximum number of elements in queue is n - 1
 */
 template<typename T>
 void Queue<T>::enqueue(T a) {
   /* resize the queue if it is full  */
   if (isFull()) {
     resize(cap, 2 * cap);
     cap *= 2; /* double the capacity */
   }
   /* check if we need to 'wrap around' */
   if ( tail == (cap - 1) ) {
     items[tail] = a;
     tail = (tail + 1) % cap;
   } else 
     items[tail++] = a;
   count++;
 }

/* 
 * dequeue
 * -------
 * Removes an item from the head of the queue. If the array is being sparsely
 * utilized this function first halves the array (although this could be 
 * a little risky since we don't know where the head and tail might be positioned).
 * This operation has a constant amortized cost, O(1). Note that we first check 
 * whether we need to resize the array (the case where count <= (capacity - 1) / 4). 
 * If this case holds, we halve the array (just like we did in the stack case, you can view
 * the stack.h code below:
 * https://github.com/rezeile/data-structure-implementations/tree/master/stack/ar-stack.h).
 *
 * The rationale for resizing before returning our item in this case is the fact that 
 * it doesn't require shifting or adjusting the head and tail indices. Once we have
 * properly resized and modified the head and tail indices in the resize operation (or
 * rather after), we can simply invoke items[head] and retrieve the head element. 
 */
template<typename T>
T Queue<T>::dequeue() {
  if(isEmpty())
  	throw "Queue is Empty";
  /* check resize */
  if(count <= (cap - 1)/4) {
  	resize(cap,cap/2);
  }
  count--;
  return items[head++];
}

/* 
 * isEmpty
 * -------
 * Returns true if the queue is empty.
 */
 template<typename T>
 bool Queue<T>::isEmpty() {
   return head == tail;
 }

/*
 * isFull
 * ------
 * Returns true if the queue is full.
 */
 template<typename T>
 bool Queue<T>::isFull() {
   return head == ((tail + 1) % cap);
 }


/* utility function: resize 
 * ------------------------
 * This function resizes the internal array to a new size
 * specified the variable new_sz.
 */
 template<typename T>
 void Queue<T>::resize(int old_sz, int new_sz) {
   /* copy elements into new array */
   int sz = old_sz < new_sz ? old_sz : new_sz;
   T *new_items = new T[new_sz];
   /* if we're doubling */
   if(new_sz > old_sz) {
  	 for(int i = 0; i < sz; i++) 
       new_items[i] = this->items[i];
   } else { /* if we're halving */
  	 for(int i = 0; i < this->count; i++) 
  	   new_items[i] = this->items[(this->head + i) % old_sz];
  	 this->head = 0;
  	 this->tail = this->count;
   }
   delete[] this->items; /* free memory */
   this->items = new_items;
 }

