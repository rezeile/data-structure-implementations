### Data Structure Implementations

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
explicity specified otherwise. Newer data structures, which are not referenced, 
are incorporated from the Algorithm Design Manual text by Steven Skiena, and 
Introduction to Algorithms, by Cormen et al.

Finished implementations will be crossed out via a ~~strikethrough~~ whereas 
pending implementations are listed below the order they will subsequently be 
implemented.

##### Implementations

- ~~Bag (Array-based, Linked List) [Sedgewick 1.3]~~
- ~~LIFO Stack (Array-based, Linked List) [Sedgewick 1.3]~~
- ~~FIFO Queue (Array-based, Linked List) [Sedgewick 1.3]~~
- ~~Steque (Ch. 1.3.32 Creative Problems)~~
- ~~Deque (Ch. 1.3.33 Creative Problems)~~
- Map (backed by a HashTable (w/ chaining & open addressing)
- Priority Queue (backed w/ traditional binary heap, van-emde-boas trees, and fibonnacci heaps)
- Trie
- Set (backed by a Red Black Tree)
- Binary Search Tree (unbalanced) 
- String (w/ JS member methods in C++)
- Suffix Tree/Array
- B-Tree
- Graph (using adjacency list/matrix, and edge lists)
- Union-Find Disjoint Sets (see Sedgewick)
- Kd-Tree
- Segment Tree
- Fenwick Tree (a.k.a Binary Indexed Tree)
- AVL Tree (implementing a set or a map)
- Splay Trees (implementing a set or map)
- Bloom Filters (implementing disjoing set)
