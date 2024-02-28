#include "my_vector.h"

#include <iostream>

template <typename T>
MyVector<T>::MyVector(const T &value) : MyVector{} {
  push_back(value);
}
template <typename T>
bool MyVector<T>::resize_array() {
  m_max_size *= 1.5;
  T *new_region = nullptr;
  try {
    new_region = new T[m_max_size];
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return false;
  }

  for (size_t i = 0; i < m_size; i++) {
    new_region[i] = m_data[i];
  }
  m_data = new_region;
  delete[] new_region;
  return true;
}
template <typename T>
bool MyVector<T>::push_back(const T &value){
  if (m_size + 1 == m_max_size)
    if (resize_array() == false) return false;
  m_data[m_size] = value;
  m_size++;
  return true;
};
template <typename T>
bool MyVector<T>::erase(const int index) {
  if (index < 0 || index > m_size) {
    std::cout << "The container element does not exist\n";
    return false;
  }
  for (size_t i = index; i <= size(); i++) {
    m_data[i] = m_data[i + 1];
  }
  m_size--;
  return true;
}
template <typename T>
bool MyVector<T>::insert(const int index, const T &value) {
  if (index < 0 || index > size()) return false;
  if (index == m_size)
    push_back(value);
  else {
    T cache = m_data[index];
    m_data[index] = value;
    for (int i = index; i < size(); i++) {
      int next_value = m_data[i + 1];
      m_data[i + 1] = cache;
      cache = next_value;
    }
    m_size++;
  }
  return true;
}
template <typename T>
T &MyVector<T>::operator[](const int index) const {
  return m_data[index];
}
template <typename T>
void MyVector<T>::print() const {
  for (int i = 0; i < size(); i++) {
    std::cout << m_data[i] << ' ';
  }
  std::cout << std::endl;
}