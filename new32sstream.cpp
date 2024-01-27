#include <iostream>

#include <sstream>

int main() {

  int num = 42;

  std::stringstream ss;

  ss << num;

  std::string str = ss.str();

  std::cout << "The string representation of " << num << " is: " << str << std::endl;
  

  return 0;

}
