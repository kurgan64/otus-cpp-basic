#pragma once

template <typename T>
class MyVector {
 public:
  MyVector() : m_max_size(5), m_data{new T[m_max_size]}, m_size(0) {}
  explicit MyVector(const T&);
  bool push_back(const T&);
  bool erase(const int index);
  bool insert(const int index, const T& value);
  int size() const { return m_size; }
  int max_size() const { return m_max_size; };
  T& operator[](const int index) const;
  void print() const;
  ~MyVector() { delete[] m_data; }

 private:
  int m_max_size;
  T* m_data;
  int m_size;
  bool resize_array();
};
#include "my_vector.cpp"