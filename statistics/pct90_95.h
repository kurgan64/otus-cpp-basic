#include <cmath>
#include <vector>

#include "iostream"
#include "istatistics.h"
double calc_pct(const std::vector<double> &vec, const double percent);
class Pct90 : public IStatistics {
 public:
  Pct90() {}

  void update(double next) override { vec.push_back(next); }

  double eval() const override {
    std::sort(vec.begin(), vec.end());
    return calc_pct(vec, 90);
  }

  const char *name() const override { return "pct90"; }

 private:
  std::vector<double> vec;
};
class Pct95 : public IStatistics {
 public:
  Pct95() {}

  void update(double next) override { vec.push_back(next); }

  double eval() const override {
    std::sort(vec.begin(), vec.end());
    return calc_pct(vec, 95);
  }

  const char *name() const override { return "pct95"; }

 private:
  std::vector<double> vec;
};
double calc_pct(const std::vector<double> &vec, const double percent) {
  double x, int_part, frac_part;
  x = percent / 100 * vec.size();
  frac_part = std::modf(x, &int_part);
  if (frac_part == 0.0) return vec.at(int_part - 1);
  return vec.at(int_part);
}