#include <iostream>
#include <array>
#include <cstdint>
#include <cstddef>

#include "../../../../library/array_utils.hpp"

class Mjehuric {
public:
  void solve() {
    std::array<uint8_t, N> a{};
    in >> a;
    for (std::size_t i = 0; i + 1 < N; i++) {
      for (std::size_t j = 1; j < N - i; j++) {
        if (a[j - 1] > a[j]) {
          std::swap(a[j - 1], a[j]);
          out << a << '\n';
        }
      }
    }
  }

  Mjehuric(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  static const std::size_t N = 5;
};