#include <iostream>

#include "../library/vector_io.hpp"
#include "../library/pair_io.hpp"
#include "../library/suffix_array.hpp"
#include "../library/array_io.hpp"

inline bool is_perfect_square(int64_t x) {
  auto sr = int64_t(round(sqrt(x)));
  return (sr * sr == x);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  return 0;
}