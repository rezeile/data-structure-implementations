#include <iostream>
#include "ll-stack.h"
#include <string>
using namespace std;

void basic_test1() {
	cout << "basic tests 1 " << endl;
	Stack<int> *s = new Stack<int>;
	s->push(1);
	s->push(2);
	s->push(3);
	for(int i = 0; i < 3; i++) {
		cout << s->pop() << endl;
	}
}

void basic_test2() {
	cout << "basic tests 2 " << endl;
	Stack<double> *s = new Stack<double>;
	for(double i = 0.0; i < 200.0; i++) {
		s->push(i);
		cout << s->pop() << endl;
	}
}

void string_test() {
  Stack<string> s;
  s.push("Eliezer");
  s.push("Abate");
  for(int i = 0; i < 2; i++) {
    cout << s.pop() << endl;
  }
}

int main() {
  basic_test1();
  basic_test2();
  string_test();
  return 0;
}
