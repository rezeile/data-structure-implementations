#include "ar-queue.h"
#include <iostream>
#include <string>
#include <exception>
/*
 * function: basic_test1
 * ---------------------
 * Enqueue three integers in sequential order, and then dequeue them in
 * sequential order.
 */
static void basic_test1() {
  std::cout << "Basic test. Consecutive three enqueue and dequeue." << std::endl;
  Queue<int> q;
  q.enqueue(4);
  q.enqueue(6);
  q.enqueue(8);
  for(int i = 0; i < 3; i++)
    std::cout << q.dequeue() << std::endl;
}

/*
 * function: basic_test2
 * ---------------------
 * Enqueue three consecutive strings, and dequeue them. Tests templating
 * features of the class.
 */
static void basic_test2() {
  std::cout << "Templating test with strings." << std::endl;
  Queue<std::string> q;
  q.enqueue("Eliezer");
  q.enqueue("Eshetu");
  q.enqueue("Abate");
  for(int i = 0; i < 3; i++) {
    std::cout << q.dequeue() << std::endl;
  }
}

/*
 * function: basic_test3
 * ---------------------
 * Exceed initial capacity. Enqueue more than 64 (intitial array capacity)
 * of integers sequentially and then dequeue them all.
 */
static void basic_test3() {
  std::cout << "Initial capacity exhaustion test." << std::endl;
  Queue<int> q;
  for(int i = 0; i < 100; i++)
    q.enqueue(i);
  std::cout << "[";
  for(int i = 0; i < 100; i++) {
    if(i != 99) std::cout << i << ",";
    else std::cout << i;
  }
  std::cout << "]" << std::endl;
}

/*
 * function: basic_test4
 * ---------------------
 * Alternate 5 enqueue and dequeue operations.
 */
static void basic_test4() {
  std::cout << "Alternating enqueue and dequeue" << std::endl;
  Queue<int> q;
  q.enqueue(1);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(2);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(3);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(4);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(5);
  std::cout << q.dequeue() << std::endl;
}

/* 
 * function: basic_test5
 * ---------------------
 * Catch dequeue exception.
 */
static void basic_test5() {
  Queue<int> q;
  try {
    q.dequeue();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  basic_test1();
  basic_test2();
  basic_test3();
  basic_test4();
  basic_test5();
  return 0;
}
