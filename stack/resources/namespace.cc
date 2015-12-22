#include <iostream>

/* like main I would be in the global namespace */
static void cout() {
  /* am i still undeclared */
}

namespace elie {
  static void cout() {
    std::cout << "I am in elie's namespace." << std::endl;
  }
}

int main(int argc, char *argv[]) {
  //cout << "Hello World" << endl;
  cout();
  std::cout << "Hello World" << std::endl;
  elie::cout();
  return 0;
}
