/*
 * Implementation of a templated FIFO First-Out (FIFO) queue, where elements
 * are removed from the queue in the order that they were inserted in. This
 * implementations uses a singly linked list as its internal representation.
 * The following class supports the following operations:
 *   enqueue: insert an element in the queue
 *   dequeue: remove an element from the queue
 *   size:    number of elements in the queue
 *   isEmpty: returns true if the queue is empty 
 *   
 * We note that in this implementation, unlike the implementation of the bag
 * and (array-based) stack classes, does support the queue iteration (as 
 * canonical queues do not anyway.)
 *
 * Author: Eliezer Abate (code.eliezer {at} gmail.com)
 * Last Updated: Dec 22 2015 22:08 (PST)
 */

#include <exception>
#include <iostream>
/* 
 * Linked Node
 * -----------
 */
template<typename T>
struct Node {
  T data;
  Node *next;
};
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
  private:
  	Node<T> *front;
    Node<T> *rear;
    int count;
};

/*
 * Constructor
 * -----------
 * 
 * O(1) time
 */
 template<typename T>
 Queue<T>::Queue() {
   front = rear = NULL;
   count = 0;
 }

/* 
 * Destructor 
 * ----------
 * 
 * O(1) time
 */
 template<typename T>
 Queue<T>::~Queue() {
   Node<T> *cur = front;
   while(cur != NULL) {
     Node<T> *next = cur->next;
     delete cur;
     cur = next;
   }
 }

/*
 * function: enqueue
 * -----------------
 * Adds an item to the rear of the queue. 
 * 
 * In the queue's internal representation
 * we allocate a new node that will hold the new item and make the rear Node's 
 * next pointer point to this node and we update the rear node itself to point 
 * to this node. To illustrate, consider the following illustration:
 *
 * enqueue(4)
 * enqueue(6)
 * enqueue(8)
 *
 * | 4 | 6 | 8 |
 *
 *   ^       ^
 *   |       |
 * front   rear
 *
 * The next enqueue operation will leave the internal linked list in the following
 * state:
 *
 * enqueue(2)
 *
 * | 4 | 6 | 8 | 2 |
 *
 *   ^           ^
 *   |           |
 * front        rear
 *   
 *
 */
 template<typename T>
 void Queue<T>::enqueue(T a) {
   /* allocate memory for new node and set fields */
   Node<T> *n = new Node<T>;
   n->data = a;
   n->next = NULL;
   /* add node to rear end of the queue or set rear to new node if queue is empty */
   if(isEmpty()) {
    front = n;
    front->next = NULL;
   } else {
    rear->next = n;
   }
   /* shift rear pointer */
   rear = n;
   count++;
 }

/* 
 * dequeue
 * -------
 * Removes an item from the front of the queue. As an illustration consider the 
 * following internal state of the queue following four successive enqueues:
 *
 * enqueue(4)
 * enqueue(6)
 * enqueue(8)
 * enqueue(2)
 *
 * | 4 | 6 | 8 |
 *
 *   ^       ^
 *   |       |
 * front   rear
 *
 *
 * A single dequeue operation will shift the front pointer to the front.
 *
 * dequeue() // returns 4
 * 
 * | 6 | 8 | 2
 *
 *   ^       ^
 *   |       |
 * front   rear
 * 
 */
template<typename T>
T Queue<T>::dequeue() {
  /* throw a const char * exception if client attempts to dequeue from empty queue */
  if(isEmpty())
  	throw "Queue is Empty";
  /* obtain front data */
  T ret = front->data;
  Node<T> *temp = front->next;
  /* delete front node and modify structure */
  if(front) delete front;
  front = temp;
  count--;
  return ret;
}

/* 
 * isEmpty
 * -------
 * Returns true if the queue is empty.
 */
 template<typename T>
 bool Queue<T>::isEmpty() {
   return count == 0;
 }

 /*
  * size
  * ----
  * Returns the number of elements in the queue.
  */
 template<typename T>
 int Queue<T>::size() {
    return count;
 }


