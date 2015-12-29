### Data Structure Implementations

##### Last Edit
December 27 2015, 23:47 (PST)

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
were written so that I could brush up on my knowledge of data structures. Lastly, 
chapter and section references in this text refer to the text Introduction to 
Algorithms, by Robert Segdewick and Kevin Wayne (Fourth Edition), unless 
explicity specified otherwise.

##### Finished Implementations

- Bag (Array-based, Linked List) [Sedgewick 1.3]
- LIFO Stack (Array-based, Linked List) [Sedgewick 1.3]
- FIFO Queue (Array-based, Linked List) [Sedgewick 1.3]
- Steque (Ch. 1.3.32 Creative Problems)
- Deque (Ch. 1.3.33 Creative Problems)

##### TODO

I. More Data Structure Implementations
- Priority Queue (Section 2.7)
- ResizingDeque (1.3.33 Creative Problems)
- String (class representing a string)

II. Creative Problems
- Josephus Problem (Ch. 1.3.37 Creative Problems)
- RingBuffer (Ch. 1.3.39)
- Two stacks with a deque (Ch. 1.3.48)
- Queue with three stacks. (Ch. 1.3.49)
- Queue with two stacks. (Ch. 1.4.27)
- Stack with a queue. (Ch. 1.4.28)
- Steque with two stacks. (Ch. 1.4.29)
- Deque with a stack and a steque. (Ch. 1.4.30)
- Deque with three stacks. (Ch. 1.4.31)

II. Conceptual Problems

- Memory requirements on a 32-bit machine (Ch 1.4.33)
- Space usage for pushdown stacks (Ch 1.4.36)

