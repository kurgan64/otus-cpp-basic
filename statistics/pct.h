#include <cmath>
#include <vector>

#include "iostream"
#include "istatistics.h"

class Pct : public IStatistics {
 public:
  Pct() = delete;
  Pct(int percent) : p_percent(percent) { p_name = "pct" + std::to_string(p_percent); }

  void update(double next) override { p_vec.push_back(next); }

  double eval() const override {
    double x, int_part, frac_part;
    std::sort(p_vec.begin(), p_vec.end());
    x = static_cast<double>(p_percent) / 100 * p_vec.size();
    frac_part = std::modf(x, &int_part);
    if (frac_part > 0.0) return p_vec.at(int_part);
    return p_vec.at(int_part - 1);
  }

  const char *name() const override { return p_name.c_str(); }

 private:
  std::string p_name;
  mutable std::vector<double> p_vec;
  int p_percent;
};
