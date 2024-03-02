#include "my_list.h"

#include <iostream>

template <typename T>
void MyList<T>::push_back(const T& value) {
  ListNode<T>* node = new ListNode(value);
  if (is_empty()) {
    m_first = node;
  }
  if (m_last != nullptr) {m_last->next = node;
    node->prev = m_last;
  }
  m_last = node;
  m_size++;
}
template <typename T>
void MyList<T>::print() const {
  ListNode<T>* node = m_first;
  while (node != nullptr) {
    std::cout << node->value << " ";
    node = node->next;
  }
  std::cout << std::endl;
}
template<typename T>
void MyList<T>::rprint() const {
  ListNode<T>* node = m_last;
  while (node != nullptr) {
    std::cout << node->value << " ";
    node = node->prev;
  }
  std::cout << std::endl;
}
template <typename T>
std::string MyList<T>::to_string() const {
  std::string str;
  ListNode<T>* node = m_first;
  while (node != nullptr) {
    str += std::to_string(node->value) + ' ';
    node = node->next;
  }
  return str;
}

template <typename T>
ListNode<T>* MyList<T>::get_element(const int index) const {
  if (index == 0) return m_first;
  if (index == m_size - 1) return m_last;
  ListNode<T>* node = m_first;
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
    ListNode<T>* node = m_first;
    m_first = node->next;
    m_first->prev = nullptr;
    delete node;
    return true;
  }
  ListNode<T>* left = get_element(index - 1);
  ListNode<T>* node = left->next;
  if (node->next == nullptr) {
    m_last = left;
  } else
    left->next = node->next;
  node->next->prev = left;
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
  ListNode<T>* node = new ListNode(value);
  if (index == 0) {
    node->next = m_first;
    m_first->prev = node;
    m_first = node;
    return true;
  }
  if (index == m_size-1) {
    push_back(value);
    return true;
  }
  ListNode<T>* left = get_element(index - 1);
  node->next = left->next;
  node->prev = left;
  node->next->prev = node;
  left->next = node;
  return true;
}