//#include "ar-stack.h"
#include <iostream>
#include "ar-stack.h"
using namespace std;

void basic_test1() {
	cout << "basic tests 1 " << endl;
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	for(int i = 0; i < 3; i++) {
		cout << s.pop() << endl;
	}
}

void basic_test2() {
	cout << "basic tests 2 " << endl;
	Stack<int> s;
	for(int i = 0; i < 200; i++) {
		s.push(i);
		cout << s.pop() << endl;
	}
}

int main() {
  basic_test1();
  basic_test2();
  return 0;
}
