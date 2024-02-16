#pragma once
#include "istatistics.h"
class Mean : public IStatistics {
 public:
  Mean() : m_sum{0} {}

  void update(double next) override {
    m_count++;
    m_sum += next;
  }

  double eval() const override {
    if (m_count == 0) return 0;
    return m_sum / m_count;
  }

  //@brief очищаем результат
  void clear() {
    m_count = 0;
    m_sum = 0;
  }

  const char *name() const override { return "mean"; }

 private:
  int m_count = 0;
  double m_sum;
};