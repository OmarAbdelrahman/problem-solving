#include <iostream>
#include <vector>
#include <algorithm>

#include "../library/vector_io.hpp"

class BNeneAndTheCardGame {
public:
  void solveOne() {
    int n;
    in >> n;
    std::vector<int> a(n);
    in >> a;
    std::sort(a.begin(), a.end());
    std::vector<int> a_cnt(n + 1);
    for (const int ai : a) {
      a_cnt[ai]++;
    }
    out << std::count(a_cnt.begin(), a_cnt.end(), 2) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BNeneAndTheCardGame(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
