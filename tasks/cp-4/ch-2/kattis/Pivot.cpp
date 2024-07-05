#include <iostream>
#include <vector>
#include <cstdint>

#include "../../../../library/vector_utils.hpp"

class Pivot {
public:
  void solve() {
    int n;
    in >> n;
    std::vector<std::uint32_t> a(n);
    in >> a;
    std::vector<std::uint32_t> max_so_far(n), min_so_far(n);
    max_so_far[0] = a[0];
    min_so_far.back() = a.back();
    for (int i = 1; i < n; i++) {
      max_so_far[i] = std::max(max_so_far[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
      min_so_far[i] = std::min(min_so_far[i + 1], a[i]);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= min_so_far[i] && a[i] >= max_so_far[i]) {
        r += 1;
      }
    }
    out << r << '\n';
  }

  Pivot(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};