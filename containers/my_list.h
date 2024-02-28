#pragma once
#include "icontainer.h"

template <typename T>
struct Node {
  Node(T value_) : value(value_), next(nullptr) {}
  T value;
  Node* next;
};

template <typename T>
class MyList : public IContainer<T> {
 public:
  MyList() : m_size(0), m_first(nullptr), m_last(nullptr) {}
  void push_back(const T&) override;
  bool erase(const int index) override;
  bool insert(const int index, const T& value) override;
  int size() const override { return m_size; }
  T& operator[](const int index) const override;
  bool is_empty() { return m_first == nullptr; }
  void print() const;
  ~MyList() {
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
};

#include "my_list.cpp"