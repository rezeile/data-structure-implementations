#include "steque.hh"
#include <iostream>
#include <string>

/*
 * basictest1
 * ----------
 * a push followed by an enque, followed by 
 * a push
 */
 void basictest1() {
 	Steque<int> s;
  	s.push(4);
  	s.enqueue(5);
  	s.push(6);
  	for(int i = 0; i < 3; i++)
  	  std::cout << s.pop() << std::endl;
 }

 /*
  * basictest2
  * ----------
  * three enqueue's followed by a push
  */
  void basictest2() {
  	Steque<std::string> s;
  	s.push("Eliezer");
  	s.push("Abate");
  	s.enqueue("Koyra");
  	for(int i = 0; i < 3; i++)
  	  std::cout << s.pop() << std::endl;
  }
 
 /** Start of Main **/
 int main(int argc, char *argv[]) {
   basictest1();
   basictest2();
   return 0;
}
