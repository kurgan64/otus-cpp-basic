#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include "istatistics.h"

class Pct : public IStatistics {
 public:
  // Pct() = delete;
  Pct(int percent = 100)
      : m_percent(percent), m_name("pct" + std::to_string(m_percent)) {
    if (m_percent < 0) throw std::underflow_error("percent not less 0");
    if (m_percent > 100) throw std::overflow_error("percent not more 100");
  }

  void update(double next) override {
  m_vec.push_back(next);
}

double eval() const override {
  std::sort(m_vec.begin(), m_vec.end());
  double x = static_cast<double>(m_percent) / 100 * m_vec.size();
  double int_part = 0;
  double frac_part = std::modf(x, &int_part);
  if (frac_part > 0.0) return m_vec.at(int_part);
  return m_vec.at(int_part == 0 ? int_part : int_part - 1);
}

const char *name() const override { return m_name.c_str(); }

private:
int m_percent;
std::string m_name;
mutable std::vector<double> m_vec;
};