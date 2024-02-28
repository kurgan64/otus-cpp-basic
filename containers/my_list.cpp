#include "my_list.h"

#include <iostream>

template <typename T>
void MyList<T>::push_back(const T& value) {
  Node<T>* node = new Node(value);
  if (is_empty()) {
    m_first = node;
  }
  if (m_last != nullptr) m_last->next = node;
  m_last = node;
  m_size++;
}
template <typename T>
void MyList<T>::print() const {
  Node<T>* node = m_first;
  while (node != nullptr) {
    std::cout << node->value << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

template <typename T>
Node<T>* MyList<T>::get_element(const int index) const {
  if (index == 0) return m_first;
  if (index == m_size - 1) return m_last;
  Node<T>* node = m_first;
  for (size_t i = 1; i <= index; i++) {
    node = node->next;
  }

  return node;
}
template <typename T>
T& MyList<T>::operator[](const int index) const {
  return get_element(index)->value;
}
template <typename T>
bool MyList<T>::erase(const int index) {
  if (index < 0 || index > m_size) {
    std::cout << "The container element does not exist\n";
    return false;
  }
  m_size--;
  if (index == 0) {
    Node<T>* node = m_first;
    m_first = node->next;
    delete node;
    return true;
  }
  Node<T>* left = get_element(index - 1);
  Node<T>* node = left->next;
  if (node->next == nullptr) {
    m_last = left;
  } else
    left->next = node->next;
  delete node;
  return true;
}
template <typename T>
bool MyList<T>::insert(const int index, const T& value) {
  if (index < 0 || index > m_size) {
    std::cout << "The container element does not exist\n";
    return false;
  }
  m_size++;
  Node<T>* node = new Node(value);
  if (index == 0) {
    node->next = m_first;
    m_first = node;
    return true;
  }
  if (index == m_size) {
    push_back(value);
    return true;
  }
  Node<T>* left = get_element(index - 1);
  node->next = left->next;
  left->next = node;
  return true;
}