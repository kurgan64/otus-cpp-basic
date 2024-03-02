#include "my_vector.h"

#include <string>
template <typename T>
MyVector<T>::MyVector(const T &value) : MyVector{} {
  push_back(value);
}
template <typename T>
bool MyVector<T>::resize_array() {
  m_max_size *= 1.5;
  T *new_region = nullptr;
  try {
    new_region = new T[m_max_size]{};
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return false;
  }
  for (size_t i = 0; i < m_size; i++) {
    new_region[i] = m_data[i];
  }
  delete[] m_data;
  m_data = new_region;
  return true;
}
template <typename T>
void MyVector<T>::push_back(const T &value) {
  if (m_size == m_max_size)
    if (resize_array() == false) return;
  m_data[m_size] = value;
  m_size++;
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
std::string MyVector<T>::to_string() const {
  std::string str;
  for (int i = 0; i < size(); i++) {
    str += std::to_string(m_data[i]) + ' ';
  }
  return str;
}