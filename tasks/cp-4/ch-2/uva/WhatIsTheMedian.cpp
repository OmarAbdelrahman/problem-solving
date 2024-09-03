#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

/*
 * I used std::nth_element to get the element that should be in the middle when the vector is sorted in O(n), but
 * is can be still done with std::sort and pick the middle elements.
 */
class WhatIsTheMedian {
public:
  void solve() {
    std::vector<uint32_t> v;
    for (uint32_t n; in >> n; ) {
      v.emplace_back(n);
      const auto mid = uint32_t (v.size()) / 2;
      std::nth_element(v.begin(), v.begin() + mid, v.end());
      if (v.size() % 2 == 0) {
        std::nth_element(v.begin(), v.begin() + (mid - 1), v.end());
        out << (v[mid - 1] + v[mid]) / 2 << '\n';
      } else {
        out << v[mid] << '\n';
      }
    }
  }

  WhatIsTheMedian(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};