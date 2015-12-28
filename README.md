### Data Structure Implementations

##### Last Edit
December 27 2015, 22:12 (PST)

##### Brief Description

This directory contains implementations of commonly known data structures in 
c++. Each data structure is located in its own sub-directory (ex. stack/).
Within each directory there is a ".h" file which implements a c++ templeted 
generic container. For example, within the stack.h file, the entire class 
definition and implementation can be found. 

Furthermore, there is also an associated [data-structure]test.cpp file, which 
performs basic tests on the data structure. For example, within the stack/ 
folder, there is a stacktest.cpp file, which performs a test on the various operations 
of a stack (namely, its push, pop, isEmpty, and size operations.)

These implementations are not intended to be robust and comprehensive, and 
were written so that I could brush up on my knowledge of data structures.

##### Finished Implementations

- Bag (Array-based, Linked List) [Sedgewick 1.3]
- LIFO Stack (Array-based, Linked List) [Sedgewick 1.3]
- FIFO Queue (Array-based, Linked List) [Sedgewick 1.3]
- Steque (Ch. 1.3.32 Creative Problems)

##### TODO

###### From Sedgewick, Introduction to Algorithms 

I. Implementation

Ch. 1 Fundamentals: 1.3 Bags, Queues, and Stacks
- Deque (Ch. 1.3.33 Creative Problems)
- Josephus Problem (Ch. 1.3.37 Creative Problems)
- RingBuffer (Ch. 1.3.39)
- Two stacks with a deque (Ch. 1.3.48)
- Queue with three stacks. (Ch. 1.3.49)
Ch. 1 Fundamentals: 1.4 Analysis of Algorithms
- Queue with two stacks. (Ch. 1.4.27)
- Stack with a queue. (Ch. 1.4.28)
- Steque with two stacks. (Ch. 1.4.29)
- Deque with a stack and a steque. (Ch. 1.4.30)
- Deque with three stacks. (Ch. 1.4.31)

II. Conceptual Problems

Ch. 1 Fundamentals: 1.4 Analysis of Algorithms
- Memory requirements on a 32-bit machine (Ch 1.4.33)
- Space usage for pushdown stacks (Ch 1.4.36)

###### From C++ STL Library

- Vector
- List
- Forward_List
- Deque
- Set
- MultiSet
- Map
- MultiMap
- Unordered Map
- Unordered Multimap
- Unordered Set
- Unordered Multiset

