/* 
 * A class definition for a stack of integers. A stack is a data structure 
 * (an object that stores and organizes data in a computer) that allows
 * users to place items in it for storage as well as access or remove the 
 * stored items. The cannonical stack is the Last In First Out (LIFO) stack,
 * whose name derives from the fact that the last item placed on the stack
 * is the first that can be accessed. 
 *
 * For example, if a user stores the items 8, 7, 4 in a LIFO stack, they will 
 * be stored internally in the following manner:
 * 
 *    --------
 *       4
 *    --------
 *       7
 *    --------
 *       8
 *    --------
 * 
 * It is worth noting that in a traditional LIFO stack, only a single item can 
 * be removed from the stack at any single time, and this single item is the 
 * most recent item placed in the stack (the 'last' in LIFO). Thus if the same
 * user that placed 8, 7, 4 removes the top most item from the stack, after the
 * removal, the stack will internally look like the following:
 * 
 *    --------
 *       7
 *    --------
 *       8
 *    --------
 *
 * This stack supports standard stack operations such as pop(), which removes 
 * an element from the top of the stack, peek(), which allows access to the 
 * element without removal, and push(), which places an element on the 
 * top of the stack. Additionally, this stack also includes the count() operation, 
 * which returns the number of elements which are currently in the stack, and 
 * a boolean returning isEmpty() operation which returns true if the stack is 
 * empty, and false otherwise.
 * 
 * Author: Eliezer Abate
 * Last Edit: 12/12/15
 * 
 * Sources Consulted: 
 *   1. Introduction to Algorithims (Third Edition): Cormen, Leiserson, Rivest, Stein
 *      (CLRS)
 * 
 * Further Reading:
 *   The Introduction to Algorithms text by (CLRS) provides a detailed account of a
 *   stack and its typical operation. Another great textbook that provides a solid 
 *   exposition about the stack data structure and how it is used is Robert Sedgewick's
 *   and Kevin Wayne's Algorithm's text. 
 */



