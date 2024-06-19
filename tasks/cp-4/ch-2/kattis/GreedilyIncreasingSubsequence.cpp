#include <iostream>
#include <vector>

#include "../../../../library/vector_utils.hpp"

class GreedilyIncreasingSubsequence {
public:
  void solve() {
    int n;
    in >> n;
    std::vector<int> a(n);
    in >> a;
    std::vector<int> r(1, a[0]);
    for (int i = 1; i < n; i++) {
      if (a[i] > r.back()) {
        r.emplace_back(a[i]);
      }
    }
    out << r.size() << '\n';
    out << r << '\n';
  }

  GreedilyIncreasingSubsequence(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};