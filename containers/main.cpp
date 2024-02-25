#include <iostream>

#include "my_vector.h"
int main() {
  MyVector<int> vec{42};

  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  vec.print();

  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "max_size: " << vec.max_size() << std::endl;
  std::cout << "Erase elements" << std::endl;
  for (int i = 2; i < 5; i++) {
    vec.erase(i);
  }
  vec.print();

  std::cout << "Insert value to begin" << std::endl;
  vec.insert(0, 10);
  vec.print();
  std::cout << "Insert value to middle" << std::endl;
  vec.insert(vec.size() / 2, 20);
  vec.print();

  std::cout << "Insert value to end" << std::endl;
  vec.insert(vec.size(), 30);
  vec.print();

  return 0;
}