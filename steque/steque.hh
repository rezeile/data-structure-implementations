/* 
 * Implementation of a stack ended queue. A stack ended queue is a data 
 * structure that supports the following operations:
 *
 * pop      [remove an item from the head of the queue]
 * push     [add an item to the head of the queue]
 * enqueue  [add an item to the tail (bottom) of the queue]
 *
 * The following implementation uses a linked list to internally 
 * represent the queue.
 *
 * Author: Eliezer Abate
 * Last Edited: Dec 27 2015 20:39 PST
 */

 #include <stddef.h>
 #include <exception>

 #ifndef _STEQUE_HH
 #define _STEQUE_HH
 /*
  * Node of our linked list.
  */
  template<typename T>
  struct Node {
   	T data;
  	Node *next;
  };

  /*
   * class: Steque
   */
  template<typename T>
  class Steque {
    public:
      Steque();
      ~Steque();
      void push(T item);
      T pop();
      void enqueue(T item);
      bool empty();
      int size();
    private:
      Node<T> *head;
      Node<T> *tail;
      int count;
  };

  
  /* Member function definitions.*/
 
  /*
   * constructor: Steque
   */
   template<typename T>
   Steque<T>::Steque() {
     /* initialize empty queue */
     head = NULL;
     tail = NULL;
     count = 0;
   }

  /*
   * destructor: ~Steque()
   */
   template<typename T>
   Steque<T>::~Steque() {
     Node<T> *cur = head;
     while(cur != NULL) {
       Node<T> *next = cur->next;
       delete cur;
       cur = next;
     }
   }

    /*
     * member function: push
     * ---------------------
     * adds an item to the head
     * of the queue.
     */
     template<typename T>
     void Steque<T>::push(T item) {
     	/* allocate new node and place item in it */
     	Node<T> *n = new Node<T>;
     	n->data = item;
     	n->next = NULL;
     	if(empty()) {
     		/* set both head and tail to the new node */
     		head = tail = n;
     	} else {
     		/* add new head */
     		n->next = head;
     		head = n;
     	}
     	count++;
     }

     /*
      * member function: enqueue
      * ------------------------
      * adds an item to the tail 
      * of the queue.
      */
      template<typename T>
      void Steque<T>::enqueue(T item) {
      	/* allocate new node for item */
      	Node<T> *n = new Node<T>;
      	n->data = item;
      	n->next = NULL;
      	if(empty()) {
      		tail = head = n;
      	} else {
      		tail->next = n;
      		tail = n;
      	}
      	count++;
      }

     /*
      * member function: pop
      * --------------------
      * removes an item, a node, 
      * from the head of the queue.
      */
      template<typename T>
      T Steque<T>::pop() {
      	if(empty())
      		throw "cannot pop from an empty steque";
      	T ret = head->data;
      	/* save head */
      	Node<T> *del = head;
      	/* set head to new head */
      	head = head->next;
      	delete del;
      	count--;
      	return ret;
      }

      /*
       * member function: size
       * ---------------------
       * returns the number of elements 
       * that are currently in the queuue.
       */
       template<typename T>
       int Steque<T>::size() {
         return count;
       }

      /*
       * member function: empty
       * ----------------------
       * returns true if the queue is 
       * empty, false otherwise.
       */
       template<typename T>
       bool Steque<T>::empty() {
         return count == 0;
       }

#endif




