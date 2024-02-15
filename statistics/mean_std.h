#include <vector>

#include "istatistics.h"
class Mean : public IStatistics {
 public:
  Mean() : m_sum{0} {}

  void update(double next) override {
    count++;
    m_sum += next;
  }

  double eval() const override {
    if (!count) return 0;
    return m_sum / count;
  }

  //@brief очищаем результат
  void clear() {
    count = 0;
    m_sum = 0;
  }

  const char *name() const override { return "mean"; }

 private:
  int count = 0;
  double m_sum;
};
class Std : public IStatistics {
 public:
  Std() : m_sum{0} {}

  void update(double next) override {
    m_sum += next;
    vec.push_back(next);
  }

  double eval() const override {
    Mean mean;
    for (const auto &v : vec) {
      mean.update(v);
    }
    // перезаписывает в вектор квадраты отклонений
    for (auto &v : vec) {
      v = std::pow((v - mean.eval()), 2);
    }

    mean.clear();
    for (const auto &v : vec) {
      mean.update(v);
    }
    return std::sqrt(mean.eval());
  }

  const char *name() const override { return "std"; }

 private:
  mutable std::vector<double> vec;
  double m_sum;
};