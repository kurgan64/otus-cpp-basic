#pragma once
#include "icontainer.h"
#include "node.h"
#include <string>

// template <typename T>
// struct Node {
//   Node(T value_) : value(value_), next(nullptr) {}
//   T value;
//   Node* next;
// };

template <typename T>
class MyForwardList : public IContainer<T> {
 public:
  MyForwardList() : m_size(0), m_first(nullptr), m_last(nullptr), m_name("Forward List") {}
  void push_back(const T&) override;
  bool erase(const int index) override;
  bool insert(const int index, const T& value) override;
  int size() const override { return m_size; }
  T& operator[](const int index) const override;
  bool is_empty() { return m_first == nullptr; }
  void print() const;
  std::string to_string() const override;
  std::string_view name() const override { return m_name; };
  ~MyForwardList() {
    while (m_first != nullptr) {
      Node<T>* node = m_first;
      m_first = node->next;
      delete node;
    }
  }

 private:
  Node<T>* get_element(const int index) const;
  int m_size;
  Node<T>* m_first;
  Node<T>* m_last;
  std::string_view m_name;
};

#include "my_forward_list.cpp"