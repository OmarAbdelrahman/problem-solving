#include <iostream>
#include <array>
#include <cstdint>
#include <cstdio>

#include "../../../../library/array_utils.hpp"

/*
 * Application of insertion-sort, count how many shifts you need to shift the values after each selection.
 */
class HeightOrdering {
public:
  void solve() {
    int n;
    in >> n;
    while (n-- != 0) {
      int ci;
      std::array<uint32_t, N> a;
      in >> ci >> a;

      uint32_t count = 0;
      for (std::size_t selection = 1; selection < N; selection++) {
        std::size_t where = 0;
        while (a[selection] > a[where]) {
          where += 1;
        }
        const uint32_t selected = a[selection];
        count += (selection - where);
        for (std::size_t k = 0; k < selection - where; k++) {
          a[selection - k] = a[selection - k - 1];
        }
        a[where] = selected;
      }

      out << ci << ' ' << count << '\n';
    }
  }

  HeightOrdering(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  static const std::size_t N = 20;
};