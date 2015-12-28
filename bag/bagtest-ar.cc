/*
 * This client program accepts a list of numbers from 
 * standard input and then returns their average. The 
 * program is primarily intended to test the 'iterability'
 * of the bag class (defined in bag.h within this same 
 * directory).
 *
 * Author: Eliezer Abate
 * Last Edited: Dec 14, 2015 20:19 (PST)
 */
#include <iostream>
#include <string>
#include "ar-bag.hh"

static void doubleTest() {
  Bag<double> numbers;
  double n;
  /* read input from STDIN */
  while(std::cin >> n)
    numbers.add(n);
  int N = numbers.size();

  double sum = 0.0;
  double cnt = 0.0;
  for(auto x = numbers.begin(); x != numbers.end(); ++x) {
    sum += *x;
    cnt++;
  }
  std::cout << "Average: " << sum / cnt << std::endl;
}

static void stringTest() {
  Bag<std::string> fam;
  std::string family[5] = {"Ben","Elie","Mishi","Tate","Ababa"};
  /* add to bag */
  for(int i = 0; i < 5; i++) {
    fam.add(family[i]);
  }
  /* range based for-loop output */
  for(std::string s: fam) {
    std::cout << "Hi this is " << s << std::endl;
  }
}

static void intTest() {
  Bag<int> l;
  int nums[3] = {3,6,9};
  /* add to bag */
  for(int i = 0; i < 3; i++) {
    l.add(nums[i]);
  }
  /* range based for-loop output */
  for(auto i = l.begin(); i != l.end(); ++i) 
    std::cout << *i << std::endl;
}


int main() {
  doubleTest();
  stringTest();
  intTest();
  return 0;
}
