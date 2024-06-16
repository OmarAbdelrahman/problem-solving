#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <cassert>

#include "../library/vector_utils.hpp"

class AGuessTheMaximum {
public:
  void solveOne() {
    int n;
    in >> n;
    std::vector<int> a(n);
    in >> a;
    int small = std::numeric_limits<int>::max();
    for (int i = 1; i < n; i++) {
      small = std::min(small, std::max(a[i], a[i - 1]));
    }
    out << small - 1 << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  AGuessTheMaximum(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};