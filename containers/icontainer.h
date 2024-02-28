#pragma once
template <typename T>
class IContainer {
 public:
  ~IContainer() {}
  virtual void push_back(const T&) = 0;
  virtual bool erase(const int) = 0;
  virtual bool insert(const int, const T&) = 0;
  virtual int size() const = 0;
  virtual T& operator[](const int) const = 0;
};