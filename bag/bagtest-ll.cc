#include "ll-bag.h"
#include <iostream>
#include <string>

static void intTest() {
  Bag<int> lilJohn;
  int nums[3] = {3,6,9};
  /* add to bag */
  for(int i = 0; i < 3; i++) {
    lilJohn.add(nums[i]);
  }
  /* range based for-loop output */
  for(int n: lilJohn) {
    std::cout << n << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::cout << "Hello World" << std::endl;
  intTest();
  return 0;
}
