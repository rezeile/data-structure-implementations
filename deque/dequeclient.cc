#include "deque.hh"
#include <iostream>
#include <string>

/*
 * basictest1
 * ----------
 * a push followed by an enque, followed by 
 * a push
 */
 void basictest1() {
 	Deque<int> s;
  	s.pushLeft(4);
    s.pushLeft(5);
    s.pushLeft(6);
    s.print();
    s.popLeft();
    s.popLeft();
    s.popLeft();
  	s.print();
  }

 /*
  * basictest2
  * ----------
  * three enqueue's followed by a push
  */
  void basictest2() {
  	Deque<std::string> s;
  	s.pushRight("Eliezer");
  	s.pushRight("Abate");
  	s.pushRight("Koyra");
    s.print();
    s.popLeft();
    s.popLeft();
    s.popLeft();
  	s.print();
  }

/*
 * basictest3
 * ----------
 * three pushes followed by popRights
 */
 void basictest3() {
  Deque<int> s;
    s.pushLeft(4);
    s.pushLeft(5);
    s.pushLeft(6);
    s.print();
    for(int i = 0; i < 3; i++) {
      s.popRight();
      s.print();
    }
  }

/*
 * basictest4
 * ----------
 * three pushRights followed by popLefts
 */
 void basictest4() {
  Deque<int> s;
    s.pushRight(4);
    s.pushRight(5);
    s.pushRight(6);
    s.print();
    for(int i = 0; i < 3; i++) {
      s.popLeft();
      s.print();
    }
  }
 
 /** Start of Main **/
 int main(int argc, char *argv[]) {
   basictest1();
   basictest2();
   basictest3();
   basictest4();
   return 0;
}
