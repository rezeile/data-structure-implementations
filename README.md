### Data Structure Implementations

##### Last Edit
December 13 2015, 21:08 (PST)

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

- Bag (Array-Based) [Sedgewick 1.3]
- LIFO Stack (Array-Based) [Sedgewick 1.3]
- FIFO Queue (Array-Based) [Sedgewick 1.3]

##### TODO

###### From Sedgewick, Introduction to Algorithms 

I. Implementation

1. Ch. 1 Fundamentals: 1.3 Bags, Queues, and Stacks
- Bag (Linked List) [Ch. 1.3]
- LIFO Stack (Linked List) [Ch. 1.3]
- FIFO Queue (Linked List) [Ch. 1.3]
- Steque (Ch. 1.3.32 Creative Problems)
- Deque (Ch. 1.3.33 Creative Problems)
- Josephus Problem (Ch. 1.3.37 Creative Problems)
- RingBuffer (Ch. 1.3.39)
- Two stacks with a deque (Ch. 1.3.48)
- Queue with three stacks. (Ch. 1.3.49)
2. Ch. 1 Fundamentals: 1.4 Analysis of Algorithms
- Queue with two stacks. (Ch. 1.4.27)
- Stack with a queue. (Ch. 1.4.28)
- Steque with two stacks. (Ch. 1.4.29)
- Deque with a stack and a steque. (Ch. 1.4.30)
- Deque with three stacks. (Ch. 1.4.31)

II. Conceptual Problems
1. Ch. 1 Fundamentals: 1.4 Analysis of Algorithms
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

