#pragma once
#include "icontainer.h"
#include <string>

template <typename T>
class MyVector : public IContainer<T> {
 public:
  MyVector() : m_max_size(9), m_data{new T[m_max_size]{}}, m_size(0), m_name("Vector") {}
  explicit MyVector(const T&);
  void push_back(const T&) override;
  bool erase(const int index) override;
  bool insert(const int index, const T& value) override;
  int size() const override { return m_size; }
  int max_size() const { return m_max_size; };
  T& operator[](const int index) const override;
  std::string to_string() const override;
  std::string_view name() const override { return m_name; };
  ~MyVector() { delete[] m_data; }

 private:
  int m_max_size;
  T* m_data;
  int m_size;
  std::string_view m_name;
  bool resize_array();
};
#include "my_vector.cpp"