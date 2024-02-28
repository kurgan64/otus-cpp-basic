#include <iostream>

#include "my_forward_list.h"
#include "my_vector.h"
#include "icontainer.h"
int main() {
  // const int containers_count = 2;
  // IContainer<int>* containers[containers_count];
  // containers[0] = new MyVector<int>;
  // containers[1] = new MyList<int>;


  MyVector<int> vec;
  MyForwardList<int> flist;

  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
    flist.push_back(i);
  }
  vec.print();
  flist.print();
  std::cout << "size Vector: " << vec.size() << std::endl;
  std::cout << "max_size Vector: " << vec.max_size() << std::endl;
  std::cout << "size List: " << flist.size() << std::endl;

  std::cout << "Erase elements" << std::endl;
  for (int i = 2; i < 5; i++) {
    vec.erase(i);
    flist.erase(i);
  }
  vec.print();
  flist.print();

  std::cout << "Insert value to begin" << std::endl;
  vec.insert(0, 10);
  flist.insert(0, 10);
  vec.print();
  flist.print();

  std::cout << "Insert value to middle" << std::endl;
  vec.insert(4, 20);
  flist.insert(4, 20);
  vec.print();
  flist.print();

  std::cout << "Insert value to end" << std::endl;
  vec.insert(vec.size(), 30);
  flist.insert(flist.size(), 30);
  vec.print();
  flist.print();

  return 0;
}