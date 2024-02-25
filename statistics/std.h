#include <math.h>

#include <vector>

#include "istatistics.h"
#include "mean.h"

class Std : public IStatistics {
 public:
  Std() {}

  void update(double next) override { m_vec.push_back(next); }

  double eval() const override {
    Mean mean{};
    for (const auto &v : m_vec) {
      mean.update(v);
    }
    std::vector<double> squares_deviations;
    for (auto &v : m_vec) {
      squares_deviations.push_back(std::pow((v - mean.eval()), 2));
    }

    mean.clear();
    for (const auto &sd : squares_deviations) {
      mean.update(sd);
    }
    return std::sqrt(mean.eval());
  }

  const char *name() const override { return "std"; }

 private:
  std::vector<double> m_vec;
};