//#include "ar-stack.h"
#include <iostream>
#include "bag.h"
using namespace std;

int main() {
  Bag<double> numbers;
  double n;
  while(cin >> n)
    numbers.add(n);
  int N = numbers.size();

  double sum = 0.0;
  for(double x: numbers)
    sum += x;
  return 0;
}
