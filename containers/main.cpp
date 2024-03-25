#include <iomanip>
#include <iostream>

#include "icontainer.h"
#include "my_forward_list.h"
#include "my_list.h"
#include "my_vector.h"
int main() {
  // MyVector<int> vec1;
  // for (size_t i = 0; i < 10; i++) {
  //   vec1.push_back(i);
  // }
  // std::cout << vec1.to_string() << std::endl;
  // MyVector<int> vec2;
  // for (size_t i = 10; i > 0; i--) {
  //   vec2.push_back(i);
  // }
  // std::cout << vec2.to_string() << std::endl;
  
  // MyVector<int> vec3=vec1;
  // std::cout << vec3.to_string() << std::endl;

  // vec3 = vec2;
  // std::cout << vec3.to_string() << std::endl;

  // MyVector<int> vec4;// = std::move(vec3);
  // vec4 = std::move(vec3);
  // std::cout << vec4.to_string() << std::endl;

  // std::cout << "-------------------------------------------" << std::endl;
  const int containers_count = 3;
  IContainer<int>* containers[containers_count];
  containers[0] = new MyVector<int>;
  containers[1] = new MyForwardList<int>;
  containers[2] = new MyList<int>;

  for (int j = 0; j < containers_count; j++) {
    for (int i = 0; i < 10; i++) {
      containers[j]->push_back(i);
    }
  }
  for (int j = 0; j < containers_count; j++) {
    std::cout << std::setw(12) << containers[j]->name() << "  "
              << containers[j]->to_string() << std::endl;
  }
  std::cout << std::endl;
  for (int j = 0; j < containers_count; j++) {
    std::cout << containers[j]->name() << " size " << containers[j]->size()
              << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Erase elements" << std::endl;
  for (int j = 0; j < containers_count; j++) {
    for (int i = 2; i < 5; i++) {
      containers[j]->erase(i);
    }
  }
  for (int j = 0; j < containers_count; j++) {
    std::cout << std::setw(12) << containers[j]->name() << "  "
              << containers[j]->to_string() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Insert value to begin" << std::endl;
  for (int j = 0; j < containers_count; j++) {
    containers[j]->insert(0, 10);
  }
  for (int j = 0; j < containers_count; j++) {
    std::cout << std::setw(12) << containers[j]->name() << "  "
              << containers[j]->to_string() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Insert value to middle" << std::endl;
  for (int j = 0; j < containers_count; j++) {
    containers[j]->insert(4, 20);
  }
  for (int j = 0; j < containers_count; j++) {
    std::cout << std::setw(12) << containers[j]->name() << "  "
              << containers[j]->to_string() << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Insert value to end" << std::endl;
  for (int j = 0; j < containers_count; j++) {
    containers[j]->insert(containers[j]->size(), 30);
  }
  for (int j = 0; j < containers_count; j++) {
    std::cout << std::setw(12) << containers[j]->name() << "  "
              << containers[j]->to_string() << std::endl;
  }
  for (int j = 0; j < containers_count; j++) {
    delete containers[j];
  }

  return 0;
}