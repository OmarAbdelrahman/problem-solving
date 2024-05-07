#include <iostream>
#include <cstdint>
#include <cmath>
#include <ratio>
#include <chrono>
#include <iomanip>

#include "../kattis/chrono-playground.hpp"
#include "../kattis/ratio-playground.hpp"

inline bool is_perfect_square(int64_t x) {
  auto sr = int64_t(std::round(std::sqrt(x)));
  return (sr * sr == x);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ratio_playground();
  return 0;
}
