#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <ratio>
#include <chrono>
#include <iomanip>

#include "../kattis/chrono-playground.hpp"
#include "../kattis/ratio-playground.hpp"
#include "../kattis/templates-playground.hpp"

inline bool is_perfect_square(int64_t x) {
  auto sr = int64_t(std::round(std::sqrt(x)));
  return (sr * sr == x);
}

inline void clamp_test() {
  const int low = 3, high = 5;
  for (int i = 0; i < 10; i++) {
    std::cout << i << ' ' << std::clamp(i, low, high) << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  template_main();
  return 0;
}
